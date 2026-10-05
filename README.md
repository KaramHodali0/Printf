# ft_printf

*This activity has been created as part of the 42 curriculum by kalhouda.*

## Description

The goal of this project is to recreate the behavior of the standard C `printf()` function.

The project introduces variadic functions in C and provides a deeper understanding of how arguments of different types can be passed to a function using `va_list`, `va_start`, `va_arg`, and `va_end`.

The `ft_printf` function supports the following conversions:

* `%c` — Print a single character.
* `%s` — Print a string.
* `%p` — Print a pointer address in hexadecimal format.
* `%d` — Print a decimal integer.
* `%i` — Print an integer in base 10.
* `%u` — Print an unsigned decimal integer.
* `%x` — Print a hexadecimal number using lowercase letters.
* `%X` — Print a hexadecimal number using uppercase letters.
* `%%` — Print a percent sign.

The function returns the total number of characters printed.

## Instructions

### Compilation

The project includes a `Makefile` with the following targets:

```bash
make
make clean
make fclean
make re
```

The library is compiled into:

```text
libftprintf.a
```

### Usage

Include the project header:

```c
#include "ft_printf.h"
```

Then compile your program with the generated library:

```bash
cc main.c -L. -lftprintf
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 42);
    return (0);
}
```

## Project Structure

```text
.
├── Makefile
├── ft_printf.c
├── ft_printf.h
├── print_char.c
├── print_string.c
├── print_number.c
├── print_unsigned.c
├── print_hexadecimal.c
└── print_pointer.c
```

## Concepts Learned

This project focuses on:

* Variadic functions.
* `va_list`.
* `va_start()`.
* `va_arg()`.
* `va_end()`.
* Function pointers.
* Handling different data types.
* Number conversion.
* Hexadecimal representation.
* Pointer addresses.
* Return values and error handling.
* Building a static library with `Makefile`.

## Resources

### Documentation

* `printf(3)` — C standard library documentation.
* `stdarg(3)` — Documentation for variadic functions.
* The Standard C Library — reference for standard C library concepts and behavior.

### References

* C programming documentation and manual pages.
* 42 ft_printf subject.

## AI Usage

AI was used as a learning and development aid during this project.

It was mainly used to:

* Explain C concepts and variadic functions.
* Help understand `va_list`, `va_start`, `va_arg`, and `va_end`.
* Explain compiler and Makefile errors.
* Review code and identify possible bugs.
* Clarify the behavior of the standard `printf()` function.

The implementation and understanding of the project were developed by the student, with AI used as a guide and learning resource.

