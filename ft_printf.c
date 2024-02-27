/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloyaraujo <eloyaraujo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:25:12 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/27 19:36:08 by eloyaraujo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(const char *input, va_list *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_putchar(va_arg(*arg, int));
	else if (*input == 's')
		i += print_string(va_arg(*arg, char *));
	else if (*input == 'p')
		i += print_pointer(va_arg(*arg, unsigned long long));
	else if (*input == 'i' || *input == 'd')
		i += print_int(va_arg(*arg, int));
	else if (*input == 'u')
		i += print_unsigned(va_arg(*arg, unsigned int));
	else if (*input == 'x')
		i += print_hex(va_arg(*arg, unsigned int), 16, "0123456789abcdef");
	else if (*input == 'X')
		i += print_hex(va_arg(*arg, unsigned int), 16, "0123456789ABCDEF");
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
				i += ft_putchar('%');
		}
		else
			i = i + ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (i);
}
