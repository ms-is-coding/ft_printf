/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:17:29 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/12 13:14:44 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include "libft.h"
#include <errno.h>
#include <limits.h>

int	__ft_printf_parse_precision(t_printf_parser *p)
{
	int	overflow;

	overflow = 0;
	p->prec = 0;
	if (p->match(p, '*'))
	{
		p->prec = va_arg(p->ap, int);
		return (0);
	}
	while (ft_isdigit(p->curr(p)) && !overflow)
	{
		p->prec = p->prec * 10 + p->curr(p) - '0';
		if (ft_isdigit(p->next(p)) && (p->prec > INT_MAX / 10
				|| (p->prec == INT_MAX / 10 && p->curr(p) > '7')))
			overflow = 1;
	}
	if (overflow)
	{
		errno = EOVERFLOW;
		return (1);
	}
	return (0);
}

static	void	__ft_printf_patch_width(t_printf_parser *p)
{
	if (p->width >= 0)
		return ;
	p->width = -p->width;
	p->flags |= PRINTF_FLAG_LEFTADJ;
}

int	__ft_printf_parse_width(t_printf_parser *p)
{
	int	overflow;

	overflow = 0;
	p->width = 0;
	if (p->match(p, '*'))
	{
		p->width = va_arg(p->ap, int);
		__ft_printf_patch_width(p);
		return (0);
	}
	while (ft_isdigit(p->curr(p)) && !overflow)
	{
		p->width = p->width * 10 + p->next(p) - '0';
		if (ft_isdigit(p->curr(p)) && (p->width > INT_MAX / 10
				|| (p->width == INT_MAX / 10 && *p->fmt > '7')))
			overflow = 1;
	}
	if (overflow)
	{
		errno = EOVERFLOW;
		return (1);
	}
	return (0);
}

int	__ft_printf_parse_flags(t_printf_parser *p)
{
	if (*p->fmt == '#')
		p->flags |= PRINTF_FLAG_ALTERNATE;
	else if (*p->fmt == '0')
		p->flags |= PRINTF_FLAG_ZEROPAD;
	else if (*p->fmt == '-')
		p->flags |= PRINTF_FLAG_LEFTADJ;
	else if (*p->fmt == ' ')
		;
	else
		p->flags |= PRINTF_FLAG_SIGN;
	p->fmt++;
	return (0);
}
