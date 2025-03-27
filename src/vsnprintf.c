/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsnprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:31:49 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/27 20:22:41 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_internal.h"
#include "libft_printf.h"

void	__ft_printf_invalid_format(t_printf_parser *p)
{
	(void)p;
}

int	ft_vsnprintf(char *dst, size_t size, const char *fmt, va_list ap)
{
	t_printf_parser	p;

	p.dst = dst;
	p.fmt = fmt;
	p.size = size;
	va_copy(p.ap, ap);
	__ft_printf_init_parser(&p);
	while (p.curr(&p))
	{
		__ft_printf_reset_parser(&p);
		while (p.curr(&p) && p.curr(&p) != '%')
			__ft_printf_insert(&p, *p.fmt++);
		if (!p.curr(&p))
			break ;
		p.fmt++;
		if (__ft_printf_handle_conv(&p))
			return (-1);
	}
	if (p.pos < p.size)
		p.dst[p.pos] = 0;
	va_end(p.ap);
	return (p.pos);
}
