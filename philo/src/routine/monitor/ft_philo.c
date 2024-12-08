/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/09 21:19:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine/ft_info.h"
#include "routine/monitor/ft_philo.h"
#include "utils/ft_default.h"

void	ft_philo_init(t_philo *philo, int i, t_info info)
{
	philo->time_to_last_eat = DEFAULT;
	philo->id = i + DEFAULT_BEGIN;
	philo->time_to_die = info.time_to_die;
	philo->time_to_eat = info.time_to_eat;
	philo->time_to_sleep = info.time_to_sleep;
	philo->must_eat = info.number_of_times_each_philosopher_must_eat;
}
