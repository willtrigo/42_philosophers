/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/01 01:24:34 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/ft_routine.h"
#include "utils/ft_utils.h"

t_routine	*ft_routine(void)
{
	static t_routine	routine;

	return (&routine);
}

void	ft_routine_init(char **argv, t_routine *routine)
{
	routine->data.number_of_philosophers = ft_strtoll(*argv++, NULL);
	if (routine->data.number_of_philosophers > MAX_PHILOSOPHERS)
		routine->data.number_of_philosophers = MAX_PHILOSOPHERS;
	routine->data.time_to_die = ft_strtoll(*argv++, NULL);
	routine->data.time_to_eat = ft_strtoll(*argv++, NULL) * MS_PER_SEC;
	routine->data.time_to_sleep = ft_strtoll(*argv++, NULL) * MS_PER_SEC;
	routine->data.number_of_times_each_philosopher_must_eat = UNLIMITED_MEALS;
	if (*argv)
		routine->data.number_of_times_each_philosopher_must_eat = ft_strtoll(\
			*argv, NULL);
}
