/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:54:52 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/27 20:13:05 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

// Enjoy this very thread-safe printf :)
int	ft_printf(const char *fmt, ...);
int	ft_dprintf(int fd, const char *fmt, ...);
int	ft_sprintf(char *dst, const char *fmt, ...);
int	ft_snprintf(char *dst, size_t size, const char *fmt, ...);

int	ft_vprintf(const char *fmt, va_list ap);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);
int	ft_vsprintf(char *dst, const char *fmt, va_list ap);
int	ft_vsnprintf(char *dst, size_t size, const char *fmt, va_list ap);

// not required as we won't use FILE structs
// int ft_fprintf(FILE *stream, const char *fmt, ...);
// int ft_vfprintf(FILE *stream, const char *fmt, va_list ap);

#endif
