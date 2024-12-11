/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:30:33 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 13:23:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils/ft_utils.h"

int	ft_output_error(
	char *str
) {
	ft_putendl_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}
