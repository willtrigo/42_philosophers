/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:17:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

typedef struct s_fork	t_fork;
struct s_fork
{
	pthread_mutex_t	mutex;
};

int	fork_init(
		t_fork *fork,
		int status
		);

#endif
