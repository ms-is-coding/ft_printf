/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:17:46 by smamalig          #+#    #+#             */
/*   Updated: 2025/05/04 19:14:43 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include "libft.h"

// for strerrorname_np
#define __USE_GNU

#include <string.h>
#include <errno.h>

static int	__ft_can_print(t_printf_parser *p)
{
	if (p->prec == -1)
		return (1);
	if (p->prec--)
		return (1);
	return (0);
}

void	__ft_printf_str(t_printf_parser *p, const char *s)
{
	int	len;

	if (!s && (p->prec < 0 || p->prec > 5))
		return (__ft_printf_str(p, "(null)"));
	else if (!s)
		return (__ft_printf_str(p, ""));
	len = ft_strlen(s);
	if (p->prec > -1 && p->prec < len)
		len = p->prec;
	__ft_printf_padding(p, len, PRINTF_START, PRINTF_OTHER);
	while (*s && __ft_can_print(p))
		__ft_printf_insert(p, *s++);
	__ft_printf_padding(p, len, PRINTF_END, PRINTF_OTHER);
}

void	__ft_printf_strerror(t_printf_parser *p)
{
	if (p->flags & PRINTF_FLAG_ALTERNATE)
		return (__ft_printf_str(p, strerrorname_np(errno)));
	else
		return (__ft_printf_str(p, strerror(errno)));
}
