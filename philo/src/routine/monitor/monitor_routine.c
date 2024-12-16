/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:28:43 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 14:29:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "routine/routine.h"

bool	is_death_philo(t_routine *rt)
{
	if (rt->monitor.death_philo)
		return (true);
	return (false);
}
