/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:40:53 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 05:20:15 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "config.h"

BOOL	config_init(t_config *self, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Invalid number of arguments!\n", STDERR_FILENO);
		return (FALSE);
	}
	*self = (t_config){0};
	self->is_valid = TRUE;
	self->must_eat_count = -1;
	config_philosophers_count(self, *(++argv));
	config_time_to_die(self, *(++argv));
	config_time_to_eat(self, *(++argv));
	config_time_to_sleep(self, *(++argv));
	if (argc == 6)
		config_must_eat_count(self, *(++argv));
	return (self->is_valid);
}

int	int_max(void)
{
	return ((int)(((unsigned int)-1) / 2));
}
