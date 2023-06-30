/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:12:26 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/14 13:00:50 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMESTAMP_H
# define TIMESTAMP_H

# include <stdint.h>

typedef uint_least64_t	t_timestamp_millis;

t_timestamp_millis	timestamp_millis(void);
void				timestamp_millis_sleep_until(t_timestamp_millis self);

#endif
