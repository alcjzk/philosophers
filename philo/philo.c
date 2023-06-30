/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:12:49 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:08:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef void	*(*t_start_routine)(void *);

static void	*philo_start(t_philo *self);

void	philo_init(t_philo *self, t_philosopher_id id, t_simulation *simulation)
{
	*self = (t_philo){0};
	self->id = id;
	self->simulation = simulation;
	self->config = (const t_config *)&simulation->config;
}

BOOL	philo_spawn(t_philo *self)
{
	if (pthread_create(
			&self->thread,
			NULL,
			(t_start_routine)philo_start,
			self) != 0)
	{
		return (FALSE);
	}
	self->is_valid = TRUE;
	return (TRUE);
}

static void	*philo_start(t_philo *self)
{
	(void)pthread_mutex_lock(&self->simulation->mutex_start);
	(void)pthread_mutex_unlock(&self->simulation->mutex_start);
	self->last_meal_timestamp = self->simulation->timestamp_start;
	while (TRUE)
	{
		if (!philo_think(self))
			break ;
		if (!philo_grab_fork_left(self))
			break ;
		if (!philo_grab_fork_right(self))
			break ;
		if (!philo_eat(self))
			break ;
		if (!philo_sleep(self))
			break ;
	}
	if (self->fork_right)
		fork_unlock(self->fork_right);
	if (self->fork_left)
		fork_unlock(self->fork_left);
	self->fork_left = NULL;
	self->fork_right = NULL;
	return (NULL);
}
