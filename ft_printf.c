/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:29:36 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/04 16:02:15 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			// doing work here
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	return (i);
}

int	main(void)
{
	ft_printf("hello, world");
}
