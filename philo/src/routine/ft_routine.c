/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/09 21:36:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine/ft_info.h"
#include "routine/monitor/ft_monitor.h"
#include "routine/ft_routine.h"
#include "utils/ft_default.h"

t_routine	*ft_routine(void)
{
	static t_routine	routine;

	return (&routine);
}

int	ft_routine_init(char **argv, t_routine *routine, int status)
{
	int	i;

	i = DEFAULT_INIT;
	ft_info_init(argv, &routine->info);
	status = ft_monitor_init(&routine->monitor, \
		routine->info.number_of_philosophers, status);
	while (++i < routine->info.number_of_philosophers)
		ft_philo_init(routine->monitor.arr_philo + i, i, routine->info);
	return (status);
}

void	ft_routine_destroy(t_routine *routine)
{
	ft_monitor_destroy(&routine->monitor);
}
