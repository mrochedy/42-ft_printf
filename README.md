# 42-ft_printf, by Maxime Rochedy

Here is my implementation of **ft_printf**, a custom implementation of the standard C `printf` function, realized during my 42 curriculum. This repository contains my full implementation of the **ft_printf** project, which received the score of **110/100**.

Here, you'll find a carefully crafted version that was evaluated by three different students, as well as the **Moulinette** correction tool. While every effort was made to ensure the code is bug-free, errors may still exist. Your feedback is highly appreciated!

<img width="198" alt="110/100 grade" src="https://github.com/user-attachments/assets/4be14bc6-0746-4bcb-9cd6-ee4f319ab093">

## About the Project

The main goals of the 42 **ft_printf** project are to learn variable argument lists handling, to improve our C-string manipulation and formatting skills and finally to have **our own** printf implementation, ready for use in our other 42 projects.

This repository provides a **complete implementation** of the **ft_printf** mandatory conversions: It supports a variety of format specifiers to handle different data types:

- **%c** : Prints a single character.
- **%s** : Prints a string of characters.
- **%p** : Prints a pointer address in hexadecimal format.
- **%d** or **%i** : Prints a signed decimal integer.
- **%u** : Prints an unsigned decimal integer.
- **%x** : Prints an unsigned hexadecimal integer (lowercase).
- **%X** : Prints an unsigned hexadecimal integer (uppercase).
- **%%** : Prints a literal `%` character.

These conversions allow you to manage various data types and print them in a formatted way, just like the standard `printf` function. In addition to the basic conversions, my **ft_printf** implementation also includes support for the following **flags**:

- **`#`** : Adds a prefix (`0x` for `%x` or `0X` for `%X`) when formatting hexadecimal or octal numbers.
- **` ` (space)** : Adds a space before a positive number for signed conversions (`%d`, `%i`), providing a consistent width for output alignment.
- **`+`** : Forces a plus sign (`+`) to be displayed for positive numbers, instead of just a space, making it clearer when the number is positive or negative.

These flags provide additional flexibility when formatting output, allowing for enhanced control over the appearance of your data.

This **ft_printf** implementation was coded by **Maxime Rochedy**, under the login **mrochedy**, as part of the 42 program. Instead of just printing every character one by one, I decided to dynamically allocate the output string to print it all at once.

Please note that while this code is provided for **learning purposes**, you should not copy it for your own submissions. Using this repository responsibly will help you enhance your understanding of variable argument lists and C-string formatting. Please respect the 42 school's policies on plagiarism.

## Getting Started

To use this library in your own projects, simply clone the repository and compile the files with your own project. Here's how:

```bash
git clone https://github.com/mrochedy/42-ft_printf.git
cd 42-ft_printf
make
```

Once compiled, you can link the `libftprintf.a` library with your project, like so:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf
```

Your `main.c` could, for example, look like something like that:

```c
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	a = 42;

	if (printf("s: %s, c: %c, p: %p, d: %d, i: %i,\
 u: %u, x: %x, X: %X, %%: %%, +: %+d, blabla\n", "test", 'a',
	&a, -2147, 57, -638, 42, 83418, 675) ==
	ft_printf("s: %s, c: %c, p: %p, d: %d, i: %i,\
 u: %u, x: %x, X: %X, %%: %%, +: %+d, blabla\n", "test", 'a',
	&a, -2147, 57, -638, 42, 83418, 675))
		printf("Correct\n");
	else
		printf("Wrong\n");
	return (0);
}
```

## Contributing

If you found this repository helpful, feel free to give it a ⭐️ star ⭐️ on GitHub to support its visibility! Contributions and improvements are welcome through pull requests, but please refrain from submitting this code as your own in official 42 projects.

Thank you for visiting and happy coding!
