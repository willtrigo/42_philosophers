/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:49:06 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 12:52:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "parse/arguments.h"
#include "utils/default.h"
#include "utils/utils.h"

static int	check_args(char **argv, int status);

int	parse_arguments(int argc, char **argv, int status)
{
	if (argc < MINIMUM_ARGUMENTS)
		status = output_error("philo: Invalid arguments,"\
			" the minimun arguments are required.");
	else if (argc > MAX_ARGUMENTS)
		status = output_error("philo: Invalid arguments,"\
			" the max arguments are reached.");
	if (status == EXIT_SUCCESS)
		status = check_args(argv, status);
	return (status);
}

static int	check_args(char **argv, int status)
{
	long long	nbr;
	char		*nbr_endptr;

	while (status == EXIT_SUCCESS && *argv)
	{
		nbr = ft_strtoll(*(argv++), &nbr_endptr);
		if (*nbr_endptr)
			status = output_error("philo: Invalid argument,"\
				" the argument must be a number.");
		else if (nbr <= DEFAULT || nbr > INT_MAX)
			status = output_error("philo: Invalid argument,"\
				" the argument must be a positive number "\
				"or less that INT_MAX.");
	}
	return (status);
}
