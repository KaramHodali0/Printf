/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:20:36 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/04 23:56:22 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, int uppercase)
{
	char	*hex;
	int		counter;

	counter = 0;
	if (uppercase == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n < 16)
		counter += print_char(hex[n]);
	else
	{
		counter += print_hex(n / 16, uppercase);
		counter += print_char(hex[n % 16]);
	}
	return (counter);
}
