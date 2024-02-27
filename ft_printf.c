/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaugust <elaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:54:54 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/27 21:53:36 by elaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

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
			i += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (i);
}
