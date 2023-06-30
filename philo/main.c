/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:34:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:04:09 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "config.h"
#include "simulation.h"

int	main(int argc, char **argv)
{
	t_config		config;
	t_simulation	simulation;
	int				index;

	if (!config_init(&config, argc, argv))
		return (EXIT_FAILURE);
	if (!simulation_init(&simulation, &config))
	{
		ft_putstr_fd("Failed to init simulation!\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	simulation_start(&simulation);
	index = 0;
	while (index < config.philosophers_count)
	{
		if (simulation.philosophers[index].is_valid)
			(void)pthread_join(simulation.philosophers[index].thread, NULL);
		index++;
	}
	simulation_free(&simulation);
	return (EXIT_SUCCESS);
}
