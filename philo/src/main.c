/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:17:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:05:35 by dande-je         ###   ########.fr       */
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

	status = parse_arguments(--argc, ++argv, EXIT_SUCCESS);
	if (status == EXIT_SUCCESS)
		status = routine_init(argv, routine(), status);
	routine_destroy(routine());
	return (status);
}
