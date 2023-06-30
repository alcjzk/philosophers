/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:07:00 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:05:45 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <pthread.h>
# include "config.h"
# include "template.h"
# include "philo.h"
# include "fork.h"
# include "timestamp.h"
# include "id.h"

typedef struct s_philo	t_philo;

typedef struct s_simulation
{
	t_config			config;
	t_fork				*forks;
	t_philo				*philosophers;
	pthread_mutex_t		mutex;
	pthread_mutex_t		mutex_start;
	t_timestamp_millis	timestamp_start;
	BOOL				is_running;
	BOOL				is_valid_mutex;
	BOOL				is_valid_mutex_start;
}	t_simulation;

BOOL	simulation_init(t_simulation *self, const t_config *config);
void	simulation_free(t_simulation *self);
BOOL	simulation_update(
			t_simulation *self,
			int id,
			t_state state,
			t_timestamp_millis timestamp);
void	simulation_start(t_simulation *self);
t_fork	*simulation_get_fork(t_simulation *self, t_fork_id id);

#endif
