/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:58:37 by ugerkens          #+#    #+#             */
/*   Updated: 2023/11/07 12:58:39 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_line(char *stash, int *eol_loc)
{
	size_t	len;
	char	*line;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_memcpy_gnl(line, stash, len);
	line[len] = '\0';
	if (len > 0 && line[len - 1] == '\n')
		*eol_loc = len - 1;
	return (line);
}

size_t	locate_eol(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*extract_line(char *line, char *stash, int *eol_loc, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_check;
	size_t	line_size;

	while (*eol_loc == -1)
	{
		ft_bzero_gnl(buffer, (BUFFER_SIZE + 1));
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(line);
			ft_bzero_gnl(stash, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_size = locate_eol(buffer);
		ft_strlcpy_gnl(stash, &buffer[line_size], (BUFFER_SIZE + 1));
		buffer[line_size] = '\0';
		line = ft_strjoin_gnl(line, buffer, eol_loc);
		if (read_check == 0)
		{
			ft_bzero_gnl(stash, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

int	get_next_line(int fd, char **return_line)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			eol_loc;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (EXIT_FAILURE);
	eol_loc = -1;
	line = init_line(stash[fd], &eol_loc);
	if (!line)
		return (EXIT_FAILURE);
	ft_strlcpy_gnl(stash[fd], &stash[fd][eol_loc + 1], BUFFER_SIZE + 1);
	line = extract_line(line, stash[fd], &eol_loc, fd);
	if (!line)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	*return_line = line;
	return (EXIT_SUCCESS);
}
