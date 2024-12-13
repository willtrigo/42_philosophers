/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_thread.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:35:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:17:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_THREAD_H
# define HANDLER_THREAD_H

# include "routine/handler/handler.h"
# include "routine/monitor/philo.h"

int	handler_thread(
		t_philo *philo,
		t_handler type,
		void *(*func)(void *),
		int status
		);

#endif
