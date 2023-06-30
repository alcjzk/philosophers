/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:12:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:09:49 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "id.h"
# include "fork.h"
# include "config.h"
# include "timestamp.h"
# include "simulation.h"

typedef int					t_philosopher_id;
typedef struct s_simulation	t_simulation;

typedef struct s_philo
{
	t_philosopher_id	id;
	t_simulation		*simulation;
	t_timestamp_millis	last_meal_timestamp;
	int					times_eaten;
	pthread_t			thread;
	t_fork				*fork_left;
	t_fork				*fork_right;
	const t_config		*config;
	BOOL				is_valid;
}	t_philo;

//		Philo
void	philo_init(
			t_philo *self,
			t_philosopher_id id,
			t_simulation *simulation);
BOOL	philo_spawn(t_philo *self);

//		Util
BOOL	philo_is_alive_at(t_philo *self, t_timestamp_millis timestamp);
BOOL	philo_await_death(t_philo *self);
int		philo_fork_id_left(t_philo *self);
int		philo_fork_id_right(t_philo *self);
BOOL	philo_update(
			t_philo *self,
			t_state state,
			t_timestamp_millis timestamp);

//		Actions
BOOL	philo_sleep(t_philo *self);
BOOL	philo_eat(t_philo *self);
BOOL	philo_grab_fork_right(t_philo *self);
BOOL	philo_grab_fork_left(t_philo *self);
BOOL	philo_think(t_philo *self);

#endif
