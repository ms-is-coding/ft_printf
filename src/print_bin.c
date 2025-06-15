/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:34:46 by smamalig          #+#    #+#             */
/*   Updated: 2025/05/16 10:49:16 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	__ft_printf_bin_internal(t_printf_parser *p, uintmax_t n, int iters)
{
	if (!iters)
		return ;
	__ft_printf_bin_internal(p, n >> 1, iters - 1);
	__ft_printf_insert(p, (n & 1) + '0');
}

static int	__ft_printf_print_len(t_printf_parser *parser, uintmax_t n)
{
	int	len;

	len = 0;
	if (n == 0 && parser->prec == -1)
		return (1);
	while (n)
	{
		n >>= 1;
		len++;
	}
	if (parser->prec > len)
		return (parser->prec);
	return (len);
}

int	__ft_printf_0b(t_printf_parser *p, int start, int mask)
{
	if (!(p->flags & PRINTF_FLAG_ALTERNATE))
		return (0);
	if (start && !(p->flags & PRINTF_FLAG_ZEROPAD))
		return (0);
	if (!start && p->flags & PRINTF_FLAG_ZEROPAD)
		return (0);
	__ft_printf_insert(p, '0');
	__ft_printf_insert(p, 'B' | mask);
	return (2);
}

void	__ft_printf_bin(t_printf_parser *p, uintmax_t n, int mask)
{
	const int	len = __ft_printf_print_len(p, n);
	const int	off = (n != 0 && (p->flags & PRINTF_FLAG_ALTERNATE) > 0) << 1;

	if (p->prec >= 0)
		p->flags &= ~PRINTF_FLAG_ZEROPAD;
	if (off)
		__ft_printf_0b(p, PRINTF_START, mask);
	__ft_printf_padding(p, len + off, PRINTF_START, PRINTF_NUMERIC);
	if (off)
		__ft_printf_0b(p, PRINTF_END, mask);
	__ft_printf_bin_internal(p, n, len);
	__ft_printf_padding(p, len + off, PRINTF_END, PRINTF_NUMERIC);
}
