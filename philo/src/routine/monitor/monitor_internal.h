/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:28:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 10:37:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_INTERNAL_H
# define MONITOR_INTERNAL_H

# include <stdbool.h>
# include "routine/routine.h"

bool	is_philos_must_eat(
			t_routine *rt
			);

bool	is_philo_death(
			t_routine *rt,
			long long current_time,
			int i
			);

#endif
