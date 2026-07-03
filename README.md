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

Example:
```sh
cc main.c libft.a -o program
```

## Library Details

The library defines the `t_list` type for singly linked lists and provides common utility functions. The implementations use straightforward linear scans, pointer relinking, and bounded memory copying to mirror the behavior of the standard C library while staying self-contained.

### Memory functions

- `ft_memcpy` — copies a byte sequence of length `n` by advancing through both memory regions in lockstep.
- `ft_memmove` — copies bytes safely even when the source and destination overlap by choosing a forward or backward pass depending on the pointer order.
- `ft_memset` — fills a memory block with a repeated byte value using a simple loop.
- `ft_bzero` — zeroes a region of memory by writing `0` to each byte.
- `ft_memchr` — scans memory byte by byte until it finds the target value or reaches the limit.
- `ft_memcmp` — compares two memory regions byte by byte and returns the first difference.
- `ft_calloc` — allocates a block of memory and initializes every byte to zero.

### String functions

- `ft_strlen` — walks the string until the null terminator is found.
- `ft_strlcpy` — copies up to `size - 1` characters and always appends a terminating null byte, returning the source length.
- `ft_strlcat` — appends the source string to the destination while preserving space and truncating if needed.
- `ft_strchr` — scans the string from the start until the requested character is found or the terminator is reached.
- `ft_strrchr` — scans the string from the end to find the last occurrence of the requested character.
- `ft_strncmp` — compares two strings up to `n` bytes and stops at the first difference or the limit.
- `ft_strnstr` — searches for a substring within a bounded length by comparing characters one by one.
- `ft_strdup` — allocates a new buffer and copies the original string into it.
- `ft_substr` — allocates a new string and copies a slice defined by a start index and length.
- `ft_strjoin` — allocates a new buffer large enough for both strings and copies them in sequence.
- `ft_strtrim` — removes leading and trailing characters that belong to a given set by scanning from both ends.
- `ft_split` — tokenizes a string on a delimiter by counting words and allocating each segment.
- `ft_itoa` — converts an integer to a string by extracting digits and rebuilding the number in reverse.
- `ft_strmapi` — applies a callback to each character while building a new string.
- `ft_striteri` — applies a callback to each character index in place.

### Character and conversion functions

- `ft_isalpha` — checks whether the input falls within the ASCII ranges for letters.
- `ft_isdigit` — checks whether the input is an ASCII digit.
- `ft_isalnum` — combines the letter and digit checks.
- `ft_isascii` — verifies that the value lies in the standard 7-bit ASCII range.
- `ft_isprint` — checks whether the value is a printable ASCII character.
- `ft_tolower` — maps uppercase ASCII letters to lowercase when applicable.
- `ft_toupper` — maps lowercase ASCII letters to uppercase when applicable.
- `ft_atoi` — skips whitespace, handles an optional sign, and accumulates digits into an integer.

### File descriptor output helpers

- `ft_putchar_fd` — writes a single character to the requested file descriptor.
- `ft_putstr_fd` — writes a whole string to the requested file descriptor until the null terminator.
- `ft_putendl_fd` — writes a string and appends a newline character.
- `ft_putnbr_fd` — prints an integer by recursively or iteratively emitting its decimal digits.

### Linked list utilities

- `ft_lstnew` — allocates a new node and initializes its content pointer and next link to `NULL`.
- `ft_lstadd_front` — inserts a node at the beginning of the list by relinking pointers.
- `ft_lstadd_back` — walks to the last node and appends the new node.
- `ft_lstsize` — traverses the list and counts each node.
- `ft_lstlast` — traverses the list until the final node is reached.
- `ft_lstdelone` — frees a single node and its content using a provided deletion callback.
- `ft_lstclear` — iterates through the list and deletes every node and its content.
- `ft_lstiter` — walks the list and applies a callback to each node.
- `ft_lstmap` — creates a new list by applying a callback to each node while preserving order.

### Resources
- Linux programming manual
- BSD documentation
- https://cppreference.com/
### AI Usage
> GLM has been used for creating routinous test suites

## Notes

- `libft.h` contains all function prototypes and the `t_list` struct definition.
- The library is built as a static archive (`libft.a`) with `ar rcs`.
- Written in C, compliant with the Norminette and ISO C.
