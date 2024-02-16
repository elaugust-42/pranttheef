/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloyaraujo <eloyaraujo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:12 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/16 23:40:22 by eloyaraujo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(const char *input, va_list *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char((char)va_arg(*arg, int));
	else if (*input == 's')
		i += print_string((char *)va_arg(*arg, char *));
	else if (*input == 'p')
		i += print_pointer((void *)va_arg(*arg, void *), 87);
	else if (*input == 'i' || *input == 'd')
		i += print_int((int)va_arg(*arg, int));
	else if (*input == 'u')
		i += print_unsigned((unsigned int)va_arg(*arg, unsigned int));
	else if (*input == 'x')
		i += print_hex((int)va_arg(*arg, int), 87);
	else if (*input == 'X')
		i += print_hex((int)va_arg(*arg, int), 55);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += format(input, &args);
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i = i + print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
