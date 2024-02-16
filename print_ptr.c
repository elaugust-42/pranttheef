/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloyaraujo <eloyaraujo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:29:59 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/16 23:40:51 by eloyaraujo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned long value, int *strlen)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	print_pointer(void *ptr_addr, int asc)
{
	unsigned long	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = (unsigned long)ptr_addr;
	printout = create_string(tempval, iptr);
	if (!printout)
		return (ft_putstr_fd("(nil)", 1), 6);
	while (tempval != 0 && i-- >= 0)
	{
		if ((tempval % 16) < 10)
			printout[i + 1] = (tempval % 16) + 48;
		else
			printout[i + 1] = (tempval % 16) + asc;
		tempval = tempval / 16;
	}
	i = ft_strlen(printout);
	i = i + print_string("0x");
	ft_putstr_fd(printout, 1);
	free(printout);
	if ((unsigned long)ptr_addr == 0)
		i += print_char('0');
	return (i);
}
