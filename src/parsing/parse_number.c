/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:54:51 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/10/07 21:54:51 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long long	get_limit(int sign)
{
	if (sign == 1)
		return (INT_MAX);
	return (2147483648LL);
}
static int	check_overflow(long long res, int digit, long long limit)
{
	if (res > limit / 10)
		return (1);
	if (res == limit / 10 && digit > limit % 10)
		return (1);
	return (0);
}
static int	skip_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}
int	parse_number(const char *str, int *number)
{
	int			i;
	int			sign;
	int			digit;
	long long	res;
	long long	limit;

	i = 0;
	res = 0;
	sign = skip_sign(str, &i);
	limit = get_limit(sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (check_overflow(res, digit, limit))
			return (1);
		res = res * 10 + digit;
		i++;
	}
	if (str[i] != '\0')
		return (1);
	*number = (int)(res * sign);
	return (0);
}
