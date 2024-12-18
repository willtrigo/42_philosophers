/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_shared_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 08:45:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/18 09:31:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine/routine.h"
#include "utils/default.h"

int	monitor_wait_to_eat(
	int type
) {
	if (type == SET)
	{
		if (rt()->monitor.wait_to_eat != DEFAULT_INIT)
		{
			monitor_permission(LOCK);
			rt()->monitor.wait_to_eat--;
			monitor_permission(UNLOCK);
		}
	}
	return (rt()->monitor.wait_to_eat);
}

bool	monitor_state(
	int type,
	int value
) {
	if (type == SET)
	{
		monitor_permission(LOCK);
		rt()->monitor.state = value;
		monitor_permission(UNLOCK);
	}
	return (rt()->monitor.state);
}
