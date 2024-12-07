/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 14:29:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/ft_routine.h"
#include "routine/ft_monitor.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"

t_routine	*ft_routine(void)
{
	static t_routine	routine;

	return (&routine);
}

int	ft_routine_init(char **argv, t_routine *routine, int status)
{
	routine->info.number_of_philosophers = ft_strtoll(*argv++, NULL);
	if (routine->info.number_of_philosophers > MAX_PHILOSOPHERS)
		routine->info.number_of_philosophers = MAX_PHILOSOPHERS;
	routine->info.time_to_die = ft_strtoll(*argv++, NULL);
	routine->info.time_to_eat = ft_strtoll(*argv++, NULL) * MS_PER_SEC;
	routine->info.time_to_sleep = ft_strtoll(*argv++, NULL) * MS_PER_SEC;
	routine->info.number_of_times_each_philosopher_must_eat = UNLIMITED_MEALS;
	if (*argv)
		routine->info.number_of_times_each_philosopher_must_eat = ft_strtoll(\
			*argv, NULL);
	status = ft_monitor_init(&routine->monitor, routine->info.number_of_philosophers, status);
	return (status);
}
