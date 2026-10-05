/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:23:37 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/05 14:40:18 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_string(char *str);
int	print_number(int t);
int	print_hex(unsigned long n, int uppercase);
int	print_pointer(void *ptr);
int	print_unsigned(unsigned int n);

#endif
