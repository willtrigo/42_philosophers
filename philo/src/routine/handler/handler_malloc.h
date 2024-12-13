/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_malloc.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:51:46 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:17:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_MALLOC_H
# define HANDLER_MALLOC_H

int	handler_malloc(
		void **target,
		int size,
		int status,
		char *str_err
		);

#endif
