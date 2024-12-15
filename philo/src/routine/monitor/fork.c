/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 12:53:44 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "routine/handler/handler_mutex.h"
#include "routine/monitor/fork.h"

int	fork_init(
	t_fork *fork,
	int status
) {
	if (status == EXIT_SUCCESS)
		status = handler_mutex(&fork->mutex, INIT, status);
	return (status);
}
