/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 13:32:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "routine/handler/ft_handler_malloc.h"
#include "routine/monitor/ft_fork.h"
#include "routine/monitor/ft_monitor.h"
#include "routine/monitor/ft_philo.h"
#include "utils/ft_default.h"

int	ft_monitor_init(
	t_monitor *monitor,
	int nbr_philos,
	int status
) {
	monitor->wait_to_eat = nbr_philos;
	monitor->death_philo = false;
	monitor->begin_time = DEFAULT;
	status = ft_handler_malloc((void **)&monitor->arr_philo, \
		nbr_philos * sizeof(t_philo), status, \
		"philo: malloc: fail to init philos malloc");
	if (status != EXIT_SUCCESS)
		return (status);
	status = ft_handler_malloc((void **)&monitor->arr_fork, \
		nbr_philos * sizeof(t_fork), status, \
		"philo: malloc: fail to init forks malloc");
	if (status != EXIT_SUCCESS)
		return (status);
	return (status);
}

void	ft_monitor_destroy(
	t_monitor *monitor
) {
	if (monitor->arr_philo)
		free(monitor->arr_philo);
	if (monitor->arr_fork)
		free(monitor->arr_fork);
}
