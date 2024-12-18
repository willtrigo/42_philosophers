/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:41 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 23:41:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "routine/fork/fork.h"
#include "routine/handler/handler.h"
#include "routine/philo/philo.h"
#include "routine/philo/philo_internal.h"
#include "utils/default.h"
#include "utils/utils.h"

void	philo_eat(
	t_philo *philo
) {
	const long long	current_time = get_time();

	philo_permission(LOCK, philo->id - NORMALIZE_PHILO);
	philo->time_to_last_eat = current_time + philo->time_to_die;
	philo_permission(UNLOCK, philo->id - NORMALIZE_PHILO);
	output(philo->id, current_time, "is eating");
	if (philo->must_eat != DEFAULT_INIT)
		philo->must_eat--;
	philo->is_full = true;
	usleep(philo->time_to_eat);
	drop_forks(philo);
}

void	philo_sleep(
	t_philo *philo
) {
	const long long	current_time = get_time();

	output(philo->id, current_time, "is sleeping");
	usleep(philo->time_to_sleep);
}

void	philo_think(
	t_philo *philo
) {
	const long long	current_time = get_time();

	output(philo->id, current_time, "is thinking");
}
