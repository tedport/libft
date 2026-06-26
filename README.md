*This project has been created as part of the 42 curriculum by vtarasov*

# libft

## Description

`libft` is a library project that reimplements standard library functions and linked list. The goal is to build a reusable static library with core routines for character testing, memory and string manipulation, basic input/output, and singly linked list handling.

## Instructions

1. Open a terminal in the project root.
2. Run `make` to compile all source files and create the static library `libft.a`.
3. Use `make clean` to remove object files (`*.o`).
4. Use `make fclean` to remove object files and the library archive.
5. Use `make re` to rebuild the library from scratch.

Example:

```sh
make
```

To use the library in another program, include `libft.h` and link with `libft.a`.

## Library Details

The library defines the `t_list` type for singly linked lists and provides common utility functions.

### Memory functions

- `ft_memcpy`
- `ft_memmove`
- `ft_memset`
- `ft_bzero`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

### String functions

- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`

### Character and conversion functions

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_tolower`
- `ft_toupper`
- `ft_atoi`

### File descriptor output helpers

- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Linked list utilities

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstadd_back`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

### Resources
- Linux programming manual
- BSD documentation
- https://cppreference.com/

## Notes

- `libft.h` contains all function prototypes and the `t_list` struct definition.
- The library is built as a static archive (`libft.a`) with `ar rcs`.
