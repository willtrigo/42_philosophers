/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:32:59 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/18 12:14:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

typedef enum e_handler
{
	INIT,
	CREATE,
	JOIN,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_handler;

#endif
