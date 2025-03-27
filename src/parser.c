/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:23:36 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/27 20:23:14 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static char	__ft_printf_method_curr(t_printf_parser *p)
{
	return (*p->fmt);
}

static char	__ft_printf_method_next(t_printf_parser *p)
{
	return (*p->fmt++);
}

static int	__ft_printf_method_match(t_printf_parser *p, char c)
{
	if (*p->fmt != c)
		return (0);
	p->fmt++;
	return (1);
}

void	__ft_printf_init_parser(t_printf_parser *p)
{
	p->pos = 0;
	p->curr = __ft_printf_method_curr;
	p->next = __ft_printf_method_next;
	p->match = __ft_printf_method_match;
}

void	__ft_printf_reset_parser(t_printf_parser *p)
{
	p->flags = 0;
	p->width = 0;
	p->spec_pos = 0;
	p->prec = -1;
	p->len_mod = PRINTF_LEN_NONE;
}
