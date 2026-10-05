/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:57:44 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/05 14:35:41 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int				counter;
	unsigned long	a;

	counter = 0;
	if (ptr == NULL)
	{
		counter += print_string("(nil)");
		return (counter);
	}
	a = (unsigned long)ptr;
	counter += print_string("0x");
	counter += print_hex(a, 0);
	return (counter);
}
