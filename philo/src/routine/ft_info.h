/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:01:25 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/10 21:50:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INFO_H
# define FT_INFO_H

enum e_info
{
	MAX_PHILOSOPHERS = 200,
	UNLIMITED_MEALS = -1,
};

typedef struct s_info	t_info;
struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
};

int	ft_info_init(char **argv, t_info *info, int status);

#endif
