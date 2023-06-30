/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 07:08:17 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/07 14:57:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "ft.h"

typedef struct s_config
{
	int		philosophers_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_count;
	BOOL	is_valid;
}	t_config;

int		int_max(void);
BOOL	config_init(t_config *self, int argc, char **argv);
void	config_philosophers_count(t_config *self, const char *arg);
void	config_time_to_die(t_config *self, const char *arg);
void	config_time_to_eat(t_config *self, const char *arg);
void	config_time_to_sleep(t_config *self, const char *arg);
void	config_must_eat_count(t_config *self, const char *arg);

#endif
