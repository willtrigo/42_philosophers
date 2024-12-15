/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:30:33 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 04:02:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils/utils.h"

int	output_error(
	char *str
) {
	ft_putendl_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	output(
	int philo_id,
	long long last_meal,
	char *str
) {
	printf("%lld %d %s\n", get_time() - last_meal, philo_id, str);
	return (EXIT_SUCCESS);
}
