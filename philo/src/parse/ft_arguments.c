/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:49:06 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/01 01:19:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "parse/ft_arguments.h"
#include "utils/ft_utils.h"
#include "utils/ft_default.h"

void	ft_parse_arguments(int argc, char **argv)
{
	long long	nbr;
	char		*nbr_endptr;

	if (argc < MINIMUM_ARGUMENTS)
		ft_output_error("philo: Invalid arguments,"\
			" the minimun arguments are required.");
	else if (argc > MAX_ARGUMENTS)
		ft_output_error("philo: Invalid arguments,"\
			" the max arguments are reached.");
	while (*argv)
	{
		nbr = ft_strtoll(*(argv++), &nbr_endptr);
		if (*nbr_endptr)
			ft_output_error("philo: Invalid argument,"\
				" the argument must be a number.");
		else if (nbr <= DEFAULT || nbr > INT_MAX)
			ft_output_error("philo: Invalid argument,"\
				" the argument must be a positive number "\
				"or less that INT_MAX.");
	}
}
