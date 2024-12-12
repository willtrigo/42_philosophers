/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 16:44:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/ft_info.h"
#include "routine/ft_routine.h"
#include "routine/monitor/ft_fork.h"
#include "routine/monitor/ft_monitor.h"
#include "routine/monitor/ft_philo.h"
#include "utils/ft_default.h"

t_routine	*ft_routine(void)
{
	static t_routine	routine;

	return (&routine);
}

int	ft_routine_init(
	char **argv,
	t_routine *routine,
	int status
) {
	int	i;

	i = DEFAULT_INIT;
	status = ft_info_init(argv, &routine->info, status);
	if (status == EXIT_SUCCESS)
	{
		status = ft_monitor_init(&routine->monitor, \
			routine->info.number_of_philosophers, status);
		while (status == EXIT_SUCCESS \
			&& ++i < routine->info.number_of_philosophers)
			status = ft_philo_init(routine->monitor.arr_philo + i, i, \
				routine->info, status);
		i = DEFAULT_INIT;
		while (status == EXIT_SUCCESS \
			&& ++i < routine->info.number_of_philosophers)
			status = ft_fork_init(routine->monitor.arr_fork + i, status);
	}
	return (status);
}

void	ft_routine_destroy(
	t_routine *routine
) {
	ft_monitor_destroy(&routine->monitor);
}
