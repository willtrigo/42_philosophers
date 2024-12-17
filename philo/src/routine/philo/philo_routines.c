/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:41 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 11:26:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "routine/fork/fork.h"
#include "routine/philo/philo.h"
#include "utils/utils.h"

void	philo_eat(
	t_philo *philo
) {
	const long long	current_time = get_time();

	output(philo->id, current_time, "is eating");
	philo->must_eat = false;
	philo->time_to_last_eat = current_time + philo->time_to_eat;
	usleep(philo->time_to_eat);
	drop_forks(philo);
}
