/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 04:52:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 14:46:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "routine/fork/fork.h"
# include "routine/info/info.h"
# include "routine/monitor/monitor.h"
# include "routine/philo/philo.h"

typedef struct s_routine	t_routine;
struct s_routine
{
	t_fork		*fork;
	t_philo		*philo;
	t_info		info;
	t_monitor	monitor;
};

t_routine	*rt(void);

int			routine_init(
				char **argv,
				t_routine *rt,
				int status
				);

int			routine_begin(
				t_routine *rt,
				int status
				);

void		routine_destroy(
				t_routine	*rt
				);

#endif
