/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:36:47 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/12 20:00:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	philo_sleep(t_philo *self)
{
	t_timestamp_millis	timestamp;
	t_timestamp_millis	timestamp_death;
	t_timestamp_millis	timestamp_awaken;

	timestamp = timestamp_millis();
	if (!philo_update(self, sleeping, timestamp))
		return (FALSE);
	timestamp_awaken = timestamp + self->config->time_to_sleep;
	timestamp_death = self->last_meal_timestamp + self->config->time_to_die;
	if (timestamp_death <= timestamp_awaken)
	{
		timestamp_millis_sleep_until(timestamp_death);
		(void)philo_update(self, dead, timestamp_death);
		return (FALSE);
	}
	timestamp_millis_sleep_until(timestamp_awaken);
	return (TRUE);
}

BOOL	philo_eat(t_philo *self)
{
	t_timestamp_millis	timestamp;

	timestamp = timestamp_millis();
	if (!philo_is_alive_at(self, timestamp))
	{
		(void)philo_update(self, dead, timestamp);
		return (FALSE);
	}
	self->last_meal_timestamp = timestamp;
	if (!philo_update(self, eating, timestamp))
		return (FALSE);
	timestamp_millis_sleep_until(timestamp + self->config->time_to_eat);
	self->times_eaten++;
	fork_unlock(self->fork_right);
	self->fork_right = NULL;
	fork_unlock(self->fork_left);
	self->fork_left = NULL;
	if (self->config->must_eat_count != -1)
	{
		if (self->config->must_eat_count <= self->times_eaten)
			return (FALSE);
	}
	return (TRUE);
}

BOOL	philo_grab_fork_right(t_philo *self)
{
	t_timestamp_millis	timestamp;
	t_fork				*fork;

	fork = simulation_get_fork(self->simulation, philo_fork_id_right(self));
	timestamp = timestamp_millis();
	if (fork == self->fork_left)
		return (philo_await_death(self));
	while (TRUE)
	{
		timestamp = timestamp_millis();
		if (!philo_is_alive_at(self, timestamp))
		{
			philo_update(self, dead, timestamp);
			return (FALSE);
		}
		if (fork_lock(fork, self))
		{
			self->fork_right = fork;
			timestamp = timestamp_millis();
			if (philo_is_alive_at(self, timestamp))
				return (philo_update(self, grabbed_fork, timestamp));
			philo_update(self, dead, timestamp);
			return (FALSE);
		}
	}
}

BOOL	philo_grab_fork_left(t_philo *self)
{
	t_timestamp_millis	timestamp;
	t_fork				*fork;

	fork = simulation_get_fork(self->simulation, philo_fork_id_left(self));
	while (TRUE)
	{
		timestamp = timestamp_millis();
		if (!philo_is_alive_at(self, timestamp))
		{
			philo_update(self, dead, timestamp);
			return (FALSE);
		}
		if (fork_lock(fork, self))
		{
			self->fork_left = fork;
			timestamp = timestamp_millis();
			if (philo_is_alive_at(self, timestamp))
				return (philo_update(self, grabbed_fork, timestamp));
			philo_update(self, dead, timestamp);
			return (FALSE);
		}
	}
}

BOOL	philo_think(t_philo *self)
{
	t_timestamp_millis	timestamp;

	timestamp = timestamp_millis();
	if (!philo_is_alive_at(self, timestamp))
	{
		(void)simulation_update(self->simulation, self->id, dead, timestamp);
		return (FALSE);
	}
	if (!simulation_update(self->simulation, self->id, thinking, timestamp))
		return (FALSE);
	return (self->config->must_eat_count != 0);
}
