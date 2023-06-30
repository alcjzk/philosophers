/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:31:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:10:04 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	philo_is_alive_at(t_philo *self, t_timestamp_millis timestamp)
{
	if (self->last_meal_timestamp + self->config->time_to_die >= timestamp)
		return (TRUE);
	return (FALSE);
}

BOOL	philo_await_death(t_philo *self)
{
	t_timestamp_millis	timestamp_death;

	timestamp_death = self->last_meal_timestamp + self->config->time_to_die;
	timestamp_millis_sleep_until(timestamp_death);
	(void)simulation_update(self->simulation, self->id, dead, timestamp_death);
	return (FALSE);
}

int	philo_fork_id_left(t_philo *self)
{
	return (self->id - 1);
}

int	philo_fork_id_right(t_philo *self)
{
	return (self->id % self->config->philosophers_count);
}

BOOL	philo_update(t_philo *self, t_state state, t_timestamp_millis timestamp)
{
	return (simulation_update(self->simulation, self->id, state, timestamp));
}
