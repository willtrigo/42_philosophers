/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:17:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/14 23:18:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse/arguments.h"
#include "routine/routine.h"

int	main(
	int argc,
	char **argv
) {
	int	status;

	status = EXIT_SUCCESS;
	if (parse_arguments(--argc, ++argv, status) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (status == EXIT_SUCCESS)
		status = routine_init(argv, rt(), status);
	routine_destroy(rt());
	return (status);
}
