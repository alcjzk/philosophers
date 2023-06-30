/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:22:26 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/30 10:07:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_H
# define TEMPLATE_H

# include "timestamp.h"
# include "state.h"

# define TEMPLATE_FORK	"%llu %u has taken a fork\n"
# define TEMPLATE_EAT	"%llu %u is eating\n"
# define TEMPLATE_SLEEP	"%llu %u is sleeping\n"
# define TEMPLATE_THINK	"%llu %u is thinking\n"
# define TEMPLATE_DIED	"%llu %u died\n"

typedef char	*t_template;

t_template	template_from_state(t_state state);
void		template_print(
				const t_template self,
				t_timestamp_millis timestamp,
				int philosopher_id);

#endif
