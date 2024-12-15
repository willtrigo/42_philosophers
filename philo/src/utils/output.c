/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:30:33 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:12:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils/utils.h"

int	output_error(
	char *str
) {
	ft_putendl_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}