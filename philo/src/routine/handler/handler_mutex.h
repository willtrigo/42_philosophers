/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mutex.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:22:04 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:17:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_MUTEX_H
# define HANDLER_MUTEX_H

# include <pthread.h>
# include "routine/handler/handler.h"

int	handler_mutex(
		pthread_mutex_t *mutex,
		t_handler type,
		int status
		);

#endif
