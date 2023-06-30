/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:36:50 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/06/08 09:41:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stddef.h>

# define BOOL char
# define TRUE 1
# define FALSE 0

int			ft_isdigit(int c);
BOOL		ft_isspace(char c);
long long	ft_strtonum(
				const char *str,
				long long min,
				long long max,
				const char **errstr);

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(const char *str, int fd);

#endif
