/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:58:44 by ugerkens          #+#    #+#             */
/*   Updated: 2023/11/07 12:58:46 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# if BUFFER_SIZE > 125000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **return_line);
char	*extract_line(char *line, char *stash, int *eol_loc, int fd);
char	*init_line(char *stash, int *eol_loc);
size_t	locate_eol(char *line);

size_t	ft_strlen_gnl(const char *s);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2, int *eol_loc);
void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);

#endif