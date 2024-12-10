/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/09 22:47:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "routine/monitor/ft_fork.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"

int	ft_fork_init(t_fork *fork, int status)
{
	if (pthread_mutex_init(&fork->mutex, NULL) != DEFAULT)
		status = ft_output_error("philo: mutex: fail to init mutex fork");
	return (status);
}
