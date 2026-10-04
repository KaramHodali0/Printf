/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 22:48:42 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/04 22:57:07 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int print_string(char *str)
{
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
    write(1, str, str_len(str));
    return (str_len(str));
}