/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 14:30:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "routine/ft_philo.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"
#include "routine/ft_monitor.h"

int	ft_monitor_init(t_monitor *monitor, int nbr_philos, int status)
{
	monitor->nbr_philos = nbr_philos;
	monitor->death_philo = false;
	monitor->begin_time = DEFAULT;
	monitor->arr_philo = malloc(nbr_philos * sizeof(t_philo));
	if (!monitor->arr_philo)
		status = ft_output_error("philo: malloc: fail to init philos malloc");
	return (status);	
}
