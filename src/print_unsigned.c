/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:40:57 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/06 18:04:16 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	__ft_printf_uint_internal(t_printf_parser *parser, __uint128_t n)
{
	if (n >= 10)
		__ft_printf_uint_internal(parser, n / 10);
	__ft_printf_insert(parser, n % 10 + '0');
}

void	__ft_printf_uint(t_printf_parser *parser, __uint128_t n)
{
	const int	len = __ft_printf_uint_len(n);

	__ft_printf_padding(parser, len, PRINTF_START, PRINTF_NUMERIC);
	if (n >= 10)
		__ft_printf_uint_internal(parser, n / 10);
	__ft_printf_insert(parser, n % 10 + '0');
	__ft_printf_padding(parser, len, PRINTF_END, PRINTF_NUMERIC);
}
