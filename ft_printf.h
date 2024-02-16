/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaugust <elaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:37:08 by elaugust          #+#    #+#             */
/*   Updated: 2024/02/15 16:42:48 by elaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

int		ft_printf(const char *__format, ...);
int		print_char(char c);
int		print_string(char *str);
int		print_pointer(void *ptr_addr);
int		print_int(int n);
int		print_unsigned(unsigned int nbr);
int		print_hex(unsigned int nbr, int asc);

#endif
