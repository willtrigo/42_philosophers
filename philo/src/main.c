/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:17:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/11/30 23:14:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse/ft_arguments.h"
#include "routine/ft_routine.h"

int	main(int argc, char **argv)
{
	ft_parse_arguments(--argc, ++argv);
	ft_routine_init(argv, ft_routine());
	exit(EXIT_SUCCESS);
}
