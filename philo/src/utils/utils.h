/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:17:03 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 12:14:17 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

long long	ft_strtoll(
				const char *str,
				char **endptr
				);

void		ft_putendl_fd(
				char *s,
				int fd
				);

int			output_error(
				char *str
				);

int			output(
				int philo_id,
				long long output_time,
				char *str
				);

long long	get_time(void);

#endif
