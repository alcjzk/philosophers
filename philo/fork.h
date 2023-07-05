/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:25:04 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/05 12:51:26 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>
# include "id.h"
# include "ft.h"

typedef struct s_philo	t_philo;

typedef struct s_fork
{
	t_philo_id		previous_id;
	pthread_mutex_t	mutex;
	BOOL			is_taken;
	BOOL			is_valid;
}	t_fork;

BOOL	fork_lock(t_fork *self, t_philo *philo);
void	fork_unlock(t_fork *self);
BOOL	fork_init(t_fork *self);
void	fork_destroy(t_fork *self);

#endif
