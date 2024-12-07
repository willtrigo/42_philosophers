/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 04:52:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 14:26:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUTINE_H
# define FT_ROUTINE_H

# include "routine/ft_monitor.h"

typedef _Atomic long int	t_pthread_mutex;

typedef struct s_info		t_info;
struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
};

typedef struct s_routine	t_routine;
struct s_routine
{
	t_info		info;
	t_monitor	monitor;
};

t_routine	*ft_routine(void);
int			ft_routine_init(char **argv, t_routine *routine, int status);

#endif
