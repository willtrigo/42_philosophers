/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:52:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:18:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils/default.h"
#include "utils/utils.h"

int	handler_malloc(
	void **target,
	int size,
	int status,
	char *str_err
) {
	if (size <= DEFAULT)
		status = output_error(str_err);
	if (status == EXIT_SUCCESS)
	{
		*target = malloc(size);
		if (!*target)
			status = output_error(str_err);
	}
	return (status);
}
