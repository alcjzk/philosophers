/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:00:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:11:27 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulation.h"

void	simulation_free(t_simulation *self)
{
	int	index;

	if (self->is_valid_mutex)
		(void)pthread_mutex_destroy(&self->mutex);
	if (self->is_valid_mutex_start)
		(void)pthread_mutex_destroy(&self->mutex_start);
	if (self->forks)
	{
		index = self->config.philosophers_count;
		while (--index > 0)
			fork_destroy(&self->forks[index]);
		free(self->forks);
	}
	if (self->philosophers)
		free(self->philosophers);
	*self = (t_simulation){0};
}

BOOL	simulation_update(
	t_simulation *self,
	t_philosopher_id id,
	t_state state,
	t_timestamp_millis timestamp)
{
	(void)pthread_mutex_lock(&self->mutex);
	if (!self->is_running)
	{
		(void)pthread_mutex_unlock(&self->mutex);
		return (FALSE);
	}
	if (state == dead)
		self->is_running = FALSE;
	template_print(template_from_state(state), timestamp, id);
	(void)pthread_mutex_unlock(&self->mutex);
	return (TRUE);
}

void	simulation_start(t_simulation *self)
{
	int	index;

	index = 0;
	(void)pthread_mutex_lock(&self->mutex_start);
	while (index < self->config.philosophers_count)
	{
		philo_spawn(&self->philosophers[index]);
		index++;
	}
	self->timestamp_start = timestamp_millis();
	(void)pthread_mutex_unlock(&self->mutex_start);
}

t_fork	*simulation_get_fork(t_simulation *self, t_fork_id id)
{
	return (&self->forks[id]);
}
