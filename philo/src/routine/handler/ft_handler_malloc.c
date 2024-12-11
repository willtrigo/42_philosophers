/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:52:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 13:33:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils/ft_utils.h"

int	ft_handler_malloc(
	void **target,
	int size,
	int status,
	char *str_err
) {
	*target = malloc(size);
	if (!*target)
		status = ft_output_error(str_err);
	return (status);
}
