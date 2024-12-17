/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:30:33 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 11:21:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "routine/monitor/monitor.h"
#include "routine/routine.h"
#include "utils/default.h"
#include "utils/utils.h"

int	output_error(
	char *str
) {
	ft_putendl_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	output(
	int philo_id,
	long long output_time,
	char *str
) {
	const long long	current_time = output_time - rt()->monitor.begin_time;

	if (monitor_state(GET, DEFAULT))
	{
		monitor_log_permission(LOCK);
		printf("%lld %d %s\n", current_time, philo_id, str);
		monitor_log_permission(UNLOCK);
	}
	return (EXIT_SUCCESS);
}
