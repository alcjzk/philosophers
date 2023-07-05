/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_impl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:50:41 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/05 17:15:31 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "config.h"

void	config_philosophers_count(t_config *self, const char *arg)
{
	const char	*errstr;

	if (!self->is_valid)
		return ;
	errstr = NULL;
	self->philosophers_count = ft_strtonum(arg, 1, int_max(), &errstr);
	if (!errstr)
		return ;
	ft_putstr_fd("Invalid number of philosophers!\n", STDERR_FILENO);
	self->is_valid = FALSE;
}

void	config_time_to_die(t_config *self, const char *arg)
{
	const char	*errstr;

	if (!self->is_valid)
		return ;
	errstr = NULL;
	self->time_to_die = ft_strtonum(arg, 1, int_max(), &errstr);
	if (!errstr)
		return ;
	ft_putstr_fd("Invalid time to die!\n", STDERR_FILENO);
	self->is_valid = FALSE;
}

void	config_time_to_eat(t_config *self, const char *arg)
{
	const char	*errstr;

	if (!self->is_valid)
		return ;
	errstr = NULL;
	self->time_to_eat = ft_strtonum(arg, 1, int_max(), &errstr);
	if (!errstr)
		return ;
	ft_putstr_fd("Invalid time to eat!\n", STDERR_FILENO);
	self->is_valid = FALSE;
}

void	config_time_to_sleep(t_config *self, const char *arg)
{
	const char	*errstr;

	if (!self->is_valid)
		return ;
	errstr = NULL;
	self->time_to_sleep = ft_strtonum(arg, 1, int_max(), &errstr);
	if (!errstr)
		return ;
	ft_putstr_fd("Invalid time to sleep!\n", STDERR_FILENO);
	self->is_valid = FALSE;
}

void	config_must_eat_count(t_config *self, const char *arg)
{
	const char	*errstr;

	if (!self->is_valid)
		return ;
	errstr = NULL;
	self->must_eat_count = ft_strtonum(arg, 0, int_max(), &errstr);
	if (!errstr)
		return ;
	ft_putstr_fd(
		"Invalid number of times each philosopher must eat!\n",
		STDERR_FILENO);
	self->is_valid = FALSE;
}
