/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/09 22:29:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "routine/monitor/ft_fork.h"
#include "routine/monitor/ft_monitor.h"
#include "routine/monitor/ft_philo.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"

int	ft_monitor_init(t_monitor *monitor, int nbr_philos, int status)
{
	monitor->wait_to_eat = nbr_philos;
	monitor->death_philo = false;
	monitor->begin_time = DEFAULT;
	monitor->arr_philo = malloc(nbr_philos * sizeof(t_philo));
	if (!monitor->arr_philo)
		status = ft_output_error("philo: malloc: fail to init philos malloc");
	monitor->arr_fork = malloc(nbr_philos * sizeof(t_fork));
	if (!monitor->arr_fork)
		status = ft_output_error("philo: malloc: fail to init fork malloc");
	return (status);
}

void	ft_monitor_destroy(t_monitor *monitor)
{
	if (monitor->arr_philo)
		free(monitor->arr_philo);
	if (monitor->arr_fork)
		free(monitor->arr_fork);
}
