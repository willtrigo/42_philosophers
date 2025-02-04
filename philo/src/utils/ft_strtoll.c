/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:16:04 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:20:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils/default.h"

static void	ft_set_endptr(
				const char *str,
				char **endptr
				);

long long	ft_strtoll(
	const char *str,
	char **endptr
) {
	long long int	nb;
	long long int	sign;

	nb = DEFAULT;
	sign = DEFAULT_BEGIN;
	if (str == NULL)
		return (ZERO);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= MINUS;
	while (*str >= '0' && *str <= '9')
		nb = (nb * DECIMAL) + (*str++ - '0');
	ft_set_endptr(str, endptr);
	return (nb * sign);
}

static void	ft_set_endptr(
				const char *str,
				char **endptr
) {
	if (endptr)
		*endptr = (char *)str;
}
