/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:05:00 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 16:30:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_H
# define DEFAULT_H

enum e_default
{
	DEFAULT = 0,
	DEFAULT_BEGIN = 1,
	DEFAULT_INIT = -1,
	FAIL = -1,
	WAIT = 1,
	CHAR_BYTE = 1,
	NULL_BYTE = 1,
};

enum e_math
{
	MINUS = -1,
	DECIMAL = 10,
	ZERO = 0,
};

enum e_time_constants
{
	MS_PER_SEC = (int)1e3,
	MS_MINIMUN_PER_SEC = (int)6e4,
};

#endif
