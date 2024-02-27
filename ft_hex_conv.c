/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaugust <elaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:38:57 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/27 21:48:52 by elaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long long nbr, int base, char *str)
{
	unsigned long long	c_base;

	c_base = (unsigned long long) base;
	if (nbr < c_base)
		return (ft_putchar(str[nbr]));
	return (print_hex(nbr / base, base, str) + ft_putchar(str[nbr % base]));
}

int	print_pointer(unsigned long long ptr_addr)
{
	if (!ptr_addr)
		return (write(1, "(nil)", 5));
	return (print_string("0x") + print_hex(ptr_addr, 16, "0123456789abcdef"));
}
