/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtonum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:44:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/03/27 09:07:17 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

#define ERR_INVALID "The string did not consist solely of digit characters."
#define ERR_TOOSMALL "The result was smaller than the provided minimum value."
#define ERR_TOOLARGE "The result was larger than the provided maximum value."

// Boolean return type for _trim_start.
typedef BOOL	t_is_negative;

///						Trims the beginning of the string by incrementing the 
///						string pointer, returning a boolean describing if the 
///						number should be treated as a negative integer.
static t_is_negative	_trim_start(const char **str);

///						Returns the error value (0). If errstr_ptr is not NULL, 
///						the error string behind it will be assigned the given
///						errstr.
static long long		_error(const char **errstr_ptr, const char *errstr);

/// 					Internal implementation for positive integers.
static long long		_positive_impl(
							const char *str,
							long long min,
							long long max,
							const char **errstr);

///						Internal implementation for negative integers.
static long long		_negative_impl(
							const char *str,
							long long min,
							long long max,
							const char **errstr);

long long	ft_strtonum(
	const char *str,
	long long min,
	long long max,
	const char **errstr)
{
	BOOL		negative;

	if (errstr)
		*errstr = NULL;
	if (!str)
	{
		if (errstr)
			*errstr = (const char *)&ERR_INVALID;
		return (0);
	}
	negative = _trim_start(&str);
	while (*str == '0')
		str++;
	if (!ft_isdigit(*str) && *(str - 1) != '0')
		return (_error(errstr, (const char *)&ERR_INVALID));
	if (negative)
		return (_negative_impl(str, min, max, errstr));
	return (_positive_impl(str, min, max, errstr));
}

static t_is_negative	_trim_start(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		return (TRUE);
	}
	else if (**str == '+')
		(*str)++;
	return (FALSE);
}

static long long	_error(const char **errstr, const char *error)
{
	if (errstr)
		*errstr = error;
	return (0);
}

static long long	_positive_impl(
	const char *str,
	long long min,
	long long max,
	const char **errstr)
{
	long long	result;

	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str) - '0';
		if (result > max || result < 0)
			return (_error(errstr, (const char *)&ERR_TOOLARGE));
		str++;
	}
	if (*str)
		return (_error(errstr, (const char *)&ERR_INVALID));
	if (result < min)
		return (_error(errstr, (const char *)&ERR_TOOSMALL));
	return (result);
}

static long long	_negative_impl(
	const char *str,
	long long min,
	long long max,
	const char **errstr)
{
	long long	result;

	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 - ((*str) - '0');
		if (result < min || result >= 0)
			return (_error(errstr, (const char *)&ERR_TOOSMALL));
		str++;
	}
	if (*str)
		return (_error(errstr, (const char *)&ERR_INVALID));
	if (result > max)
		return (_error(errstr, (const char *)&ERR_TOOLARGE));
	return (result);
}
