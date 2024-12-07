/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:40 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/07 14:13:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

enum e_philo
{
	MAX_PHILOSOPHERS = 200,
	UNLIMITED_MEALS = -1,
};

typedef struct s_philo		t_philo;
struct s_philo
{
	long long	time_to_last_eat;
	int			id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
};

#endif
