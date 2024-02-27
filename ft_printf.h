/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaugust <elaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:54:48 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/27 20:29:22 by elaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int		ft_printf(const char *__format, ...);
int		ft_putchar(char c);
int		print_string(char *str);
int		print_pointer(unsigned long long ptr_addr);
int		print_int(int n);
int		print_unsigned(unsigned int nbr);
int		print_hex(unsigned long long nbr, int base, char *str);
size_t	ft_strlen(const char *str);

#endif