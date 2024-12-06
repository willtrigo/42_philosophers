/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 04:52:22 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/05 11:48:24 by dande-je         ###   ########.fr       */
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

typedef struct s_data		t_data;
struct s_data
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
	t_data	data;
};

t_routine	*ft_routine(void);
void		ft_routine_init(char **argv, t_routine *routine);

#endif
