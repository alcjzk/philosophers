/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:11:50 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 11:54:02 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "timestamp.h"

t_timestamp_millis	timestamp_millis(void)
{
	struct timeval				val;
	static t_timestamp_millis	epoch;

	(void)gettimeofday(&val, NULL);
	if (!epoch)
		epoch = val.tv_sec * 1000 + (val.tv_usec / 1000);
	return ((val.tv_sec * 1000 + (val.tv_usec / 1000)) - epoch);
}

void	timestamp_millis_sleep_until(t_timestamp_millis then)
{
	t_timestamp_millis	now;
	uint_least64_t		duration;

	now = timestamp_millis();
	if (now >= then)
		return ;
	duration = ((uint_least64_t)(then - now));
	if (duration > 10)
	{
		duration -= 10;
		usleep((duration * 1000));
	}
	now = timestamp_millis();
	while (now < then)
		now = timestamp_millis();
}
