/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:44:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/01 16:33:09 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

static BOOL	is_odd(t_philo_id philo_id);

BOOL	fork_lock(t_fork *self, t_philo_id philo_id)
{
	(void)pthread_mutex_lock(&self->mutex);	
	if (self->is_taken
		|| is_odd(self->previous_id & philo_id)
		|| !is_odd(self->previous_id | philo_id))
	{
		(void)pthread_mutex_unlock(&self->mutex);
		usleep(10);
		return (FALSE);
	}
	self->previous_id = philo_id;
	self->is_taken = TRUE;
	(void)pthread_mutex_unlock(&self->mutex);
	return (TRUE);
}

void	fork_unlock(t_fork *self)
{
	(void)pthread_mutex_lock(&self->mutex);
	self->is_taken = FALSE;
	(void)pthread_mutex_unlock(&self->mutex);
}

BOOL	fork_init(t_fork *self)
{
	*self = (t_fork){0};
	if (pthread_mutex_init(&self->mutex, NULL) != 0)
		return (FALSE);
	self->is_valid = TRUE;
	return (TRUE);
}

void	fork_destroy(t_fork *self)
{
	if (self->is_valid)
		(void)pthread_mutex_destroy(&self->mutex);
	self->is_valid = FALSE;
}

static BOOL	is_odd(t_philo_id philo_id)
{
	return (philo_id % 2 != 0);
}
