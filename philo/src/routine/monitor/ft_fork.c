/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 16:26:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "routine/monitor/ft_fork.h"
#include "routine/handler/ft_handler.h"
#include "routine/handler/ft_handler_mutex.h"

int	ft_fork_init(
	t_fork *fork,
	int status
) {
	if (status == EXIT_SUCCESS)
		status = ft_handler_mutex(&fork->mutex, INIT, status);
	return (status);
}
