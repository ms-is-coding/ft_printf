/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:05:40 by smamalig          #+#    #+#             */
/*   Updated: 2025/06/01 12:15:38 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <stdlib.h>

void	__ft_printf_handle_int(t_printf_parser *p)
{
	if (p->len_mod == PRINTF_LEN_HH)
		__ft_printf_int(p, (signed char)va_arg(p->ap, int));
	else if (p->len_mod == PRINTF_LEN_H)
		__ft_printf_int(p, (short)va_arg(p->ap, int));
	else if (p->len_mod == PRINTF_LEN_L)
		__ft_printf_int(p, (long)va_arg(p->ap, long));
	else if (p->len_mod == PRINTF_LEN_LL)
		__ft_printf_int(p, (long long)va_arg(p->ap, long long));
	else if (p->len_mod == PRINTF_LEN_Z)
		__ft_printf_int(p, (ssize_t)va_arg(p->ap, size_t));
	else
		__ft_printf_int(p, va_arg(p->ap, int));
}

void	__ft_printf_handle_uint(t_printf_parser *p)
{
	if (p->len_mod == PRINTF_LEN_HH)
		__ft_printf_uint(p, (unsigned char)va_arg(p->ap, int));
	else if (p->len_mod == PRINTF_LEN_H)
		__ft_printf_uint(p, (unsigned short)va_arg(p->ap, int));
	else if (p->len_mod == PRINTF_LEN_L)
		__ft_printf_uint(p, (unsigned long)va_arg(p->ap, long));
	else if (p->len_mod == PRINTF_LEN_LL)
		__ft_printf_uint(p, (unsigned long long)va_arg(p->ap, long long));
	else if (p->len_mod == PRINTF_LEN_Z)
		__ft_printf_uint(p, (size_t)va_arg(p->ap, size_t));
	else
		__ft_printf_uint(p, (unsigned int)va_arg(p->ap, int));
}

void	__ft_printf_handle_hex(t_printf_parser *p, int mask)
{
	if (p->len_mod == PRINTF_LEN_HH)
		__ft_printf_hex(p, (unsigned char)va_arg(p->ap, int) & 0xFF, mask);
	else if (p->len_mod == PRINTF_LEN_H)
		__ft_printf_hex(p, (unsigned short)va_arg(p->ap, int), mask);
	else if (p->len_mod == PRINTF_LEN_L)
		__ft_printf_hex(p, (unsigned long)va_arg(p->ap, long), mask);
	else if (p->len_mod == PRINTF_LEN_LL)
		__ft_printf_hex(p, (unsigned long long)va_arg(p->ap, long long), mask);
	else if (p->len_mod == PRINTF_LEN_Z)
		__ft_printf_hex(p, (size_t)va_arg(p->ap, size_t), mask);
	else
		__ft_printf_hex(p, (unsigned int)va_arg(p->ap, int), mask);
}

void	__ft_printf_handle_oct(t_printf_parser *p)
{
	if (p->len_mod == PRINTF_LEN_HH)
		__ft_printf_oct(p, (unsigned char)va_arg(p->ap, int) & 0xFF);
	else if (p->len_mod == PRINTF_LEN_H)
		__ft_printf_oct(p, (unsigned short)va_arg(p->ap, int));
	else if (p->len_mod == PRINTF_LEN_L)
		__ft_printf_oct(p, (unsigned long)va_arg(p->ap, long));
	else if (p->len_mod == PRINTF_LEN_LL)
		__ft_printf_oct(p, (unsigned long long)va_arg(p->ap, long long));
	else if (p->len_mod == PRINTF_LEN_Z)
		__ft_printf_oct(p, (size_t)va_arg(p->ap, size_t));
	else
		__ft_printf_oct(p, (unsigned int)va_arg(p->ap, int));
}

void	__ft_printf_handle_bin(t_printf_parser *p, int mask)
{
	if (p->len_mod == PRINTF_LEN_HH)
		__ft_printf_bin(p, (unsigned char)va_arg(p->ap, int) & 0xFF, mask);
	else if (p->len_mod == PRINTF_LEN_H)
		__ft_printf_bin(p, (unsigned short)va_arg(p->ap, int), mask);
	else if (p->len_mod == PRINTF_LEN_L)
		__ft_printf_bin(p, (unsigned long)va_arg(p->ap, long), mask);
	else if (p->len_mod == PRINTF_LEN_LL)
		__ft_printf_bin(p, (unsigned long long)va_arg(p->ap, long long), mask);
	else if (p->len_mod == PRINTF_LEN_Z)
		__ft_printf_bin(p, (size_t)va_arg(p->ap, size_t), mask);
	else
		__ft_printf_bin(p, (unsigned int)va_arg(p->ap, int), mask);
}
