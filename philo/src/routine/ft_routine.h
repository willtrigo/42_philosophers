/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 04:52:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/01 01:06:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUTINE_H
# define FT_ROUTINE_H

typedef _Atomic long int	t_pthread_mutex;

enum e_philo
{
	MAX_PHILOSOPHERS = 200,
	UNLIMITED_MEALS = -1,
};

enum e_scale_constants
{
	MS_PER_SEC = (int)1e3,
};

typedef struct s_info		t_info;
struct s_info
{
	int				number_of_philosophers;
	t_pthread_mutex	time_to_die;
	t_pthread_mutex	time_to_eat;
	t_pthread_mutex	time_to_sleep;
	t_pthread_mutex	number_of_times_each_philosopher_must_eat;
};

typedef struct s_routine	t_routine;
struct s_routine
{
	t_info	data;
};

t_routine	*ft_routine(void);
void		ft_routine_init(char **argv, t_routine *routine);

#endif
