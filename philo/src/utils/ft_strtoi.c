/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:16:04 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/20 03:18:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils/ft_default.h"

static void	ft_set_endptr(const char *str, char **endptr);

int	ft_strtoi(const char *str, char **endptr)
{
	int	nb;
	int	sign;

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

static void	ft_set_endptr(const char *str, char **endptr)
{
	if (endptr)
		*endptr = (char *)str;
}
