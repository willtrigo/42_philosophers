/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:41 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 19:39:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "routine/philo/philo.h"
#include "utils/default.h"
#include "utils/utils.h"

bool	is_philo_alive(
	t_philo *philo
) {
	long long	current_time;

	if (philo->is_dead)
		return (false);
	current_time = (get_time() - philo->time_to_last_eat) * MS_PER_SEC;
	if (current_time <= philo->time_to_die)
		return (true);
	philo->is_dead = true;
	output(philo->id, get_time(), "died");
	return (false);
}
