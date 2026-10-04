/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:48:05 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/05 00:56:37 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned(unsigned int n)
{
    int counter;

    counter = 0;
    if (n < 10)
    {
        counter += print_char(n + '0');
    }
    if (n >= 10)
    {
        counter += print_unsigned(n / 10);
        counter += print_char(n % 10 + '0');
    }
    return (counter);
}