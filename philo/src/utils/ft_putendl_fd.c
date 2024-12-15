/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:31:57 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 12:56:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "utils/default.h"

static size_t	ft_strlen(
					char *s
					);

void	ft_putendl_fd(
	char *s,
	int fd
) {
	if (write(fd, s, ft_strlen(s)) == FAIL)
		perror("write");
	if (write(fd, "\n", CHAR_BYTE) == FAIL)
		perror("write");
}

static size_t	ft_strlen(
	char *s
) {
	char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}
