/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:49:06 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 13:45:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "parse/ft_arguments.h"
#include "utils/ft_utils.h"
#include "utils/ft_default.h"

static int	ft_check_args(char **argv, int status);

int	ft_parse_arguments(int argc, char **argv, int status)
{
	if (argc < MINIMUM_ARGUMENTS)
		status = ft_output_error("philo: Invalid arguments,"\
			" the minimun arguments are required.");
	else if (argc > MAX_ARGUMENTS)
		status = ft_output_error("philo: Invalid arguments,"\
			" the max arguments are reached.");
	if (!status)
		status = ft_check_args(argv, status);
	return (status);
}

static int	ft_check_args(char **argv, int status)
{
	long long	nbr;
	char		*nbr_endptr;

	while (*argv)
	{
		nbr = ft_strtoll(*(argv++), &nbr_endptr);
		if (*nbr_endptr)
		{
			status = ft_output_error("philo: Invalid argument,"\
				" the argument must be a number.");
			break ;
		}
		else if (nbr <= DEFAULT || nbr > INT_MAX)
		{
			status = ft_output_error("philo: Invalid argument,"\
				" the argument must be a positive number "\
				"or less that INT_MAX.");
			break ;
		}
	}
	return (status);
}
