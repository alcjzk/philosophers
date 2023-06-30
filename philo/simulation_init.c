/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:50:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 09:54:04 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "simulation.h"

static BOOL	simulation_init_forks(t_simulation *self, int count);
static BOOL	simulation_init_philosophers(t_simulation *self, int count);

BOOL	simulation_init(t_simulation *self, const t_config *config)
{
	*self = (t_simulation){0};
	if (pthread_mutex_init(&self->mutex, NULL) != 0)
		return (FALSE);
	self->is_valid_mutex = TRUE;
	if (pthread_mutex_init(&self->mutex_start, NULL) != 0)
		return (FALSE);
	self->is_valid_mutex_start = TRUE;
	if (!simulation_init_forks(self, config->philosophers_count))
		return (FALSE);
	if (!simulation_init_philosophers(self, config->philosophers_count))
		return (FALSE);
	self->config = *config;
	self->is_running = TRUE;
	return (TRUE);
}

static BOOL	simulation_init_forks(t_simulation *self, int count)
{
	self->forks = malloc(sizeof(t_fork) * count);
	if (!self->forks)
		return (FALSE);
	while (count-- > 0)
	{
		if (!fork_init(&self->forks[count]))
			return (FALSE);
	}
	return (TRUE);
}

static BOOL	simulation_init_philosophers(t_simulation *self, int count)
{
	self->philosophers = malloc(sizeof(t_philo) * count);
	if (!self->philosophers)
		return (FALSE);
	while (count > 0)
	{
		philo_init(&self->philosophers[count - 1], count, self);
		count--;
	}
	return (TRUE);
}
