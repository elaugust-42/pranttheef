/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloyaraujo <eloyaraujo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:36:37 by eloyaraujo        #+#    #+#             */
/*   Updated: 2024/02/27 19:41:32 by eloyaraujo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str , ft_strlen(str)));
}

int	print_pointer(unsigned long long ptr_addr)
{
	if (!ptr_addr)
		return (write(1, "(nil)", 5));
	
	return (print_string("0x") + print_hex(ptr_addr, 16, "0123456789abcdef"));
}

int	print_int(int nbr)
{
	if (nbr == INT_MIN)
		return (print_string("-2147483648"));
	if (nbr < 0)
	return (ft_putchar('-') + print_int(-nbr));
	if (nbr < 10)
	return (ft_putchar(nbr + 48));
	return (print_int(nbr / 10) + ft_putchar(nbr % 10 + 48));
}

int	print_unsigned(unsigned int nbr)
{
	if (nbr < 10)
		return (ft_putchar(nbr + 48));
	return (print_int(nbr / 10) + ft_putchar(nbr % 10 + 48));   
}

int	print_hex(unsigned long long nbr, int base, char *str)
{
	int i;
	unsigned long long c_base = (unsigned long long)base;

	i = 0;
	if (nbr < c_base)
		return (ft_putchar(str[i + nbr]));
	return(print_hex(nbr / base, base, str) + ft_putchar(str[i + nbr % base]));
}