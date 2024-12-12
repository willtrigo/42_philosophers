/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_thread.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:35:23 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/12 15:44:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLER_THREAD_H
# define FT_HANDLER_THREAD_H

# include "routine/handler/ft_handler.h"
# include "routine/monitor/ft_philo.h"

int	ft_handler_thread(
		t_philo *philo,
		t_handler type,
		void *(*func)(void *),
		int status
		);

#endif
