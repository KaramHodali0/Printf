/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:57:44 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/05 00:45:55 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int				counter;
	unsigned long	a;

	if (ptr == NULL)
		counter += print_string("(nil)");
	counter = 0;
	a = (unsigned long)ptr;
	counter += print_string("0x");
	counter += print_hex(a, 0);
	return (counter);
}
