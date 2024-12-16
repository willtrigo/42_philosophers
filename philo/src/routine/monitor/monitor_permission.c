/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_permission.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:15:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 14:16:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_mutex.h"
#include "routine/routine.h"

void	monitor_permission(
	t_handler type
) {
	if (type == LOCK)
		handler_mutex(&rt()->monitor.mutex, LOCK, EXIT_SUCCESS);
	if (type == UNLOCK)
		handler_mutex(&rt()->monitor.mutex, UNLOCK, EXIT_SUCCESS);
}

void	monitor_log_permission(
	t_handler type
) {
	if (type == LOCK)
		handler_mutex(&rt()->monitor.log, LOCK, EXIT_SUCCESS);
	if (type == UNLOCK)
		handler_mutex(&rt()->monitor.log, UNLOCK, EXIT_SUCCESS);
}
