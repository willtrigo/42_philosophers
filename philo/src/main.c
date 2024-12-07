/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:17:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 14:28:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse/ft_arguments.h"
#include "routine/ft_routine.h"

int	main(int argc, char **argv)
{
	int	status;

	status = ft_parse_arguments(--argc, ++argv, EXIT_SUCCESS);
	if (!status)
		status = ft_routine_init(argv, ft_routine(), EXIT_SUCCESS);
	return (status);
}
