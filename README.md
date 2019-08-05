# ft_printf
This repository contains the library of functions written in C, including the printf() function.

As in C programming language, my ft_printf() function is used to print the “character, string, integer, octal and hexadecimal values” onto the output screen.

- printf() function with %d (%D, %i) format specifier to display the value of an integer variable;
- %c is used to display character;
- %C for unicode symbols;
- %s for string variable;
- %S for unicode strings;
- %x for hexadecimal variable written in lowercase, %X for hexadecimal variable written in uppercase;
- %o (%O) for octal.

It is also possible to use different length of argument: h, l; flags: +, -, #, space, 0; width and precision.

To use this library first of all you need to compile it. 

In the root of repository enter "make" in your terminal, press Enter and then library named "libftprintf.a" will be created. Add it to the project and you will be able to check how it works.
