/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:49:20 by dande-je          #+#    #+#             */
/*   Updated: 2024/08/20 05:47:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGUMENTS_H
# define FT_ARGUMENTS_H

enum e_arguments
{
	MINIMUM_ARGUMENTS = 5,
	MAX_ARGUMENTS = 6,
};

void	ft_parse_arguments(int argc, char **argv);

#endif
