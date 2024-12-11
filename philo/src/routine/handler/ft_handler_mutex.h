/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mutex.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:22:04 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 16:04:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLER_MUTEX_H
# define FT_HANDLER_MUTEX_H

# include <pthread.h>
# include "routine/handler/ft_handler.h"

int	ft_handler_mutex(
		pthread_mutex_t *mutex,
		t_handler type,
		int status
		);

#endif
