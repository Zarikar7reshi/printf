#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int print_char_flags(int c, t_flags flags)
{
	int	printed;

	printed = 0;
	if (flags.left)
	{
		printed += print_char(c);
		printed += pad(flags.width - 1, ' ');
	}
	else
	{
		if (flags.zero)
			printed += pad(flags.width - 1, '0');
		else
			printed += pad(flags.width - 1, ' ');
		printed += print_char(c);
	}
	return (printed);
}