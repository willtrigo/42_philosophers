/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:28:43 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 18:28:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "routine/handler/handler.h"
#include "routine/monitor/monitor.h"
#include "routine/philo/philo.h"
#include "routine/routine.h"
#include "utils/default.h"

bool	is_death_philo(
	t_routine *rt
) {
	int	i;

	i = DEFAULT_INIT;
	while (++i < rt->info.number_of_philosophers)
	{
		philo_permission(LOCK, i);
		if (rt->philo[i].is_dead)
		{
			monitor_permission(LOCK);
			rt->monitor.death_philo = true;
			monitor_permission(UNLOCK);
		}
		philo_permission(UNLOCK, i);
	}
	if (rt->monitor.death_philo)
		return (true);
	return (false);
}