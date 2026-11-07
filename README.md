*This project has been created as part of the 42 curriculum by kaaltint.*

# ft_printf

## Description

ft_printf is a C project that recreates the basic behavior of the standard `printf()` function.

The project supports the mandatory conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

It produces a static library named `libftprintf.a`.

## Instructions

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile:

```bash
make re
```

Include `ft_printf.h` in your C program and link it with `libftprintf.a`.

## Algorithm and Data Structures

The implementation scans the format string character by character.

When it encounters `%`, it identifies the conversion and calls the corresponding helper function.

Variadic arguments are handled using `va_list`, `va_start`, `va_arg`, and `va_end`.

Decimal and hexadecimal numbers are printed recursively using division and modulo operations.

No additional data structures or output buffering are used. The function keeps track of the number of printed characters and returns that count.

## Resources

- C manual pages: `man 3 printf`
- C variadic arguments: `man 3 stdarg`
- System calls: `man 2 write`
- 42 ft_printf subject and Norm documentation

AI assistance was used to explain C concepts, review code structure, identify Norminette issues, suggest tests, and support debugging. The implementation was manually entered and reviewed during development.