/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:32:59 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:18:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

typedef enum e_handler	t_handler;
enum e_handler
{
	INIT,
	CREATE,
	JOIN,
	LOCK,
	UNLOCK,
	DESTROY,
	DETACH
};

#endif
