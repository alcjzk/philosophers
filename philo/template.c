/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:34:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:07:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "template.h"

t_template	template_from_state(t_state state)
{
	if (state == thinking)
		return (TEMPLATE_THINK);
	if (state == grabbed_fork)
		return (TEMPLATE_FORK);
	if (state == eating)
		return (TEMPLATE_EAT);
	if (state == sleeping)
		return (TEMPLATE_SLEEP);
	else
		return (TEMPLATE_DIED);
}

void	template_print(
	const t_template self,
	t_timestamp_millis timestamp,
	int philosopher_id)
{
	(void)printf(self, timestamp, philosopher_id);
}
