/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:01:29 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/19 00:55:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/info/info.h"
#include "utils/default.h"
#include "utils/utils.h"

int	info_init(
	char **argv,
	t_info *info,
	int status
) {
	info->number_of_philosophers = ft_strtoll(*argv++, NULL);
	if (info->number_of_philosophers > MAX_PHILOSOPHERS)
		info->number_of_philosophers = MAX_PHILOSOPHERS;
	info->time_to_die = ft_strtoll(*argv++, NULL);
	info->time_to_eat = ft_strtoll(*argv++, NULL) * MS_PER_SEC;
	info->time_to_sleep = ft_strtoll(*argv++, NULL) * MS_PER_SEC;
	info->number_of_times_each_philosopher_must_eat = UNLIMITED_MEALS;
	if (*argv)
		info->number_of_times_each_philosopher_must_eat = ft_strtoll(\
			*argv, NULL);
	if ((info->time_to_die * MS_PER_SEC) < MS_MINIMUN_PER_SEC \
		|| info->time_to_eat < MS_MINIMUN_PER_SEC \
		|| info->time_to_sleep < MS_MINIMUN_PER_SEC)
		status = output_error("philo: Invalid argument,"\
			" time must be at leat 60ms");
	return (status);
}
