/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaugust <elaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:54:36 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/27 20:39:39 by elaugust         ###   ########.fr       */
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
	return (write (1, str, ft_strlen(str)));
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
