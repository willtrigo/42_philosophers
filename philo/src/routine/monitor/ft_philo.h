/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:40 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/09 21:13:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

#include "routine/ft_info.h"

typedef struct s_philo	t_philo;
struct s_philo
{
	long long	time_to_last_eat;
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
};

void	ft_philo_init(t_philo *philo, int i, t_info info);

#endif
