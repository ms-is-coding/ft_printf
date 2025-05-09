/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:09:07 by smamalig          #+#    #+#             */
/*   Updated: 2025/05/09 02:44:37 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdint.h>

#define _AIX
#include <stdio.h>
#include "libft_printf.h"

union u_double {
	double dbl;
	uint64_t u64;
};

#define INT128_MIN (__int128_t)1 << 127
#define UINT128_MAX (__uint128_t)-1

#include <errno.h>

int main() {
	int mid1 = 0;
	int mid2 = 0;
	union u_double val;
	val.u64 = 0x7ff0000000000000;

//	int res1 =    printf("\e[92m%-*.*m |%-05.3d| |%p| %n\e[m\n", 14, 8, 42, &val, &mid1);
//	int res2 = ft_printf("\e[93m%-*.*m |%-05.3d| |%p| %n\e[m\n", 14, 8, 42, &val, &mid2);

	printf("|%u|\n", 42);
	ft_printf("|%u|\n", 42);

	// ft_printf("\n");
	//    printf("\e[1;94m==> %i | %i <==\e[m\n", mid1, res1);
	// ft_printf("\e[1;95m==> %i | %i <==\e[m\n", mid2, res2);
	// ft_printf("\n");
}
