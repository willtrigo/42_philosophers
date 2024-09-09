/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/09/09 08:08:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/ft_philosopher.h"
#include "utils/ft_utils.h"

t_routine	*ft_routine(void)
{
	static t_routine	routine;

	return (&routine);
}

void	ft_routine_init(char **argv)
{
	t_routine	*routine;

	routine = ft_routine();
	routine->data.number_of_philosophers = ft_strtoi(*argv, NULL);
	if (routine->data.number_of_philosophers > MAX_PHILOSOPHERS)
		routine->data.number_of_philosophers = MAX_PHILOSOPHERS;
}
