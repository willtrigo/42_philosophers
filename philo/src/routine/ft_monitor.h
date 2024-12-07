/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 14:26:25 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MONITOR_H
# define FT_MONITOR_H

# include <stdbool.h>
# include "routine/ft_philo.h"

typedef struct s_monitor	t_monitor;
struct s_monitor
{
	long long	begin_time;
	int			nbr_philos;
	bool		death_philo;
	t_philo		*arr_philo;
};

int	ft_monitor_init(t_monitor *monitor, int nbr_philos, int status);

#endif
