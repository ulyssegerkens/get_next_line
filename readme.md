<h1 align="center">
	Get Next Line
</h1>

## 📃 General information
Version: 10. Bonus included.</br>

## ⚙️ Implementation details
I spend a lot of time on this project to make it completely leak free, especially in situations where `malloc()` fails. The challenge was to send the error back to the main function and free the memory properly.</br>
The `_utils` file provides an unchanged or slightly modified [libft](https://github.com/ulyssegerkens/libft) function (in this case the `_gnl` suffix is added).</br>
Bonus files are copies of the base implementation with small modifications to handle multiple files and related includes.</br>

## ✨ Versions
The version compile by the Makefile is a more secure version made to be used in other projects as an independent library. The submitted version is the src_original directory.</br>
Change logs:
- `get_next_line` return a status and put the line in a buffer. It allows to make the difference between an error and the end of file.
- Makefile, include and build/ directory.
- Only bonus version.

## 🎉 Testing
Tested by moulinette (125%) and [francinette](https://github.com/xicodomingues/francinette) in strict mode.
