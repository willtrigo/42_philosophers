/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_thread.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:35:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 00:21:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_THREAD_H
# define HANDLER_THREAD_H

# include <bits/pthreadtypes.h>
# include "routine/handler/handler.h"

int	handler_thread(
		pthread_t *th,
		t_handler type,
		void *(*func)(void *),
		void *arg
		);

#endif
