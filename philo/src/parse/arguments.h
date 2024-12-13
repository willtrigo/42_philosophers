/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:49:20 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:18:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

enum e_arguments
{
	MINIMUM_ARGUMENTS = 4,
	MAX_ARGUMENTS = 5,
};

int	parse_arguments(int argc, char **argv, int status);

#endif
