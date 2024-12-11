/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 13:31:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MONITOR_H
# define FT_MONITOR_H

# include <stdbool.h>
# include "routine/monitor/ft_fork.h"
# include "routine/monitor/ft_philo.h"

typedef struct s_monitor	t_monitor;
struct s_monitor
{
	long long	begin_time;
	int			wait_to_eat;
	bool		death_philo;
	t_philo		*arr_philo;
	t_fork		*arr_fork;
};

int		ft_monitor_init(
			t_monitor *monitor,
			int nbr_philos,
			int status
			);

void	ft_monitor_destroy(
			t_monitor *monitor
			);

#endif
