/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:31 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 10:21:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INTERNAL_H
# define PHILO_INTERNAL_H

# include <stdbool.h>
# include "routine/philo/philo.h"

enum e_default_philo
{
	NORMALIZE_PHILO = 1,
};

void	philo_eat(
			t_philo *philo
			);

#endif
