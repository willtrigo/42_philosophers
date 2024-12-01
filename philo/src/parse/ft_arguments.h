/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:49:20 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/01 01:03:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGUMENTS_H
# define FT_ARGUMENTS_H

enum e_arguments
{
	MINIMUM_ARGUMENTS = 4,
	MAX_ARGUMENTS = 5,
};

void	ft_parse_arguments(int argc, char **argv);

#endif
