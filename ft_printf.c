/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:29:36 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/05 16:31:02 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_str(const char str, va_list *args)
{
	int	counter;

	counter = 0;
	if (str == 'c')
		counter += print_char(va_arg(*args, int));
	else if (str == 's')
		counter += print_string(va_arg(*args, char *));
	else if (str == 'd' || str == 'i')
		counter += print_number(va_arg(*args, int));
	else if (str == 'u')
		counter += print_unsigned(va_arg(*args, unsigned int));
	else if (str == 'x')
		counter += print_hex(va_arg(*args, unsigned int), 0);
	else if (str == 'X')
		counter += print_hex(va_arg(*args, unsigned int), 1);
	else if (str == 'p')
		counter += print_pointer(va_arg(*args, void *));
	else if (str == '%')
		counter += print_char('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1))
		{
			i += ft_check_str(*(str + 1), &args);
			str += 2;
		}
		else
		{
			write(1, str, 1);
			i++;
			str++;
		}
	}
	va_end(args);
	return (i);
}
