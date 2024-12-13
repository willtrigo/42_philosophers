/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 04:52:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:08:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "routine/info.h"
# include "routine/monitor/monitor.h"

typedef struct s_routine	t_routine;
struct s_routine
{
	t_info		info;
	t_monitor	monitor;
};

t_routine	*routine(void);

int			routine_init(
				char **argv,
				t_routine *routine,
				int status
				);

void		routine_destroy(
				t_routine *routine
				);

#endif
