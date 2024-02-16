/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaugust <elaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:51:21 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/15 18:23:36 by elaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (7);
	}
	while (s[i])
		i++;
	ft_putstr_fd(s, 1);
	return (i);
}
