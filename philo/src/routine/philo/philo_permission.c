/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_permission.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:12 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 14:48:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_mutex.h"
#include "routine/routine.h"

void	philo_permission(
	t_handler type,
	int id
) {
	if (type == LOCK)
		handler_mutex(&rt()->philo[id].mutex, LOCK, EXIT_SUCCESS);
	if (type == UNLOCK)
		handler_mutex(&rt()->philo[id].mutex, UNLOCK, EXIT_SUCCESS);
}
