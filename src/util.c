/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:51:08 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/27 20:23:00 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	__ft_printf_int_len(__int128_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	__ft_printf_uint_len(__uint128_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

__int128_t	__ft_printf_abs(__int128_t n)
{
	const int	mask = n >> 127;

	return ((n + mask) ^ mask);
}

char	__ft_printf_abs_char(char c)
{
	const int	mask = c >> 7;

	return ((c + mask) ^ mask);
}
