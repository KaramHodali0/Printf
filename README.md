*This activity has been created as part of the 42 curriculum by kalhouda.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C function `printf`. The goal of the project is to learn how variadic functions work in C (`<stdarg.h>`) and to build a small, reusable library (`libftprintf.a`) that formats and prints text to the standard output using only the `write` system call.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, like the original `printf`.

### Supported conversions

| Specifier | Description                                        |
|-----------|----------------------------------------------------|
| `%c`      | A single character                                 |
| `%s`      | A string (prints `(null)` if the pointer is NULL)  |
| `%p`      | A pointer in hexadecimal (prints `(nil)` if NULL)  |
| `%d`      | A signed decimal integer                           |
| `%i`      | A signed integer (decimal)                         |
| `%u`      | An unsigned decimal integer                        |
| `%x`      | An unsigned hexadecimal number (lowercase)         |
| `%X`      | An unsigned hexadecimal number (uppercase)         |
| `%%`      | A literal percent sign                             |

### Project structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c          # main function + conversion dispatcher
├── print_char.c         # %c and %%
├── print_string.c       # %s
├── print_number.c       # %d / %i
├── print_unsigned.c     # %u
├── print_hexadecimal.c  # %x / %X (also used by %p)
└── print_pointer.c      # %p
```

## Instructions

### Compilation

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`.

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + all
```

### Usage

Include the header in your source file and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, number %d, hex %x, ptr %p\n", "42", 42, 255, &len);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structures

### Parsing the format string

`ft_printf` walks through the format string one character at a time:

- If the character is not `%`, it is written directly with `write` and the counter is incremented.
- If the character is `%`, the next character is passed to a dispatcher (`ft_check_str`) that selects the right printing function, and the pointer advances by two.

The variable arguments are accessed with `va_list`, `va_start`, `va_arg` and `va_end`. The `va_list` is passed **by pointer** to the dispatcher so that each `va_arg` call advances the same argument list.

**Why this choice:** a simple `if / else if` dispatcher is easy to read, easy to extend with new specifiers, and has no overhead. A lookup table of function pointers would also work, but it adds complexity for only nine specifiers.

### Printing numbers: recursion

Integers (`%d`, `%i`, `%u`) and hexadecimal numbers (`%x`, `%X`, `%p`) are printed with a **recursive algorithm**:

1. If the number is smaller than the base (10 or 16), print the single digit.
2. Otherwise, recursively print `n / base`, then print the digit `n % base`.

This naturally outputs digits from the most significant to the least significant, so no intermediate buffer, array reversal, or dynamic memory allocation (`malloc`) is needed.

**Edge cases handled:**

- `INT_MIN`: `print_number` stores the value in a `long` before negating it, avoiding overflow when computing `-n`.
- Hexadecimal digits are looked up in a constant string (`"0123456789abcdef"` or `"0123456789ABCDEF"`), which handles both lowercase and uppercase with one function.
- `%p`: the pointer is cast to `unsigned long` (64 bits on modern systems) so that the entire address is printed. `print_hex` therefore takes an `unsigned long`; `%x`/`%X` values (`unsigned int`) are safely promoted to it.
- `NULL` strings print `(null)` and `NULL` pointers print `(nil)`, matching the behaviour of glibc on Linux.

### Return value

Every printing function returns the number of characters it wrote, and the callers add these values together. This way the total is computed without extra data structures and `ft_printf` can return it as `printf` does.

### Data structures

No complex data structure is required. The only state is:

- an `int` counter for the number of printed characters,
- a `va_list` for the variadic arguments,
- constant strings used as digit lookup tables for hexadecimal output.

## Resources

### References

- `man 3 printf`: behaviour of the original function.
- `man 3 stdarg`: variadic functions (`va_start`, `va_arg`, `va_end`).
- `man 2 write`: the system call used for output.
- [GNU C Library Manual: Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [cppreference: `printf` family](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference: `va_arg`](https://en.cppreference.com/w/c/variadic/va_arg)
- The 42 subject for `ft_printf`.

