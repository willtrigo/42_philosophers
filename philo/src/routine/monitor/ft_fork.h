/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 13:32:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORK_H
# define FT_FORK_H

# include <pthread.h>

typedef struct s_fork	t_fork;
struct s_fork
{
	pthread_mutex_t	mutex;
};

int	ft_fork_init(
		t_fork *fork,
		int status
		);

#endif
