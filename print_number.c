/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 22:58:00 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/04 23:17:11 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int t)
{
	long	n;
	int		counter;

	n = t;
	counter = 0;
	if (n < 0)
	{
		counter += print_char('-');
		n = -n;
	}
	if (n < 10)
	{
		counter += print_char(n + '0');
	}
	if (n >= 10)
	{
		counter += print_number(n / 10);
		counter += print_char(n % 10 + '0');
	}
	return (counter);
}
