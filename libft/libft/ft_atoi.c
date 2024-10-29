/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:50:15 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/09 15:15:33 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int long	convert(char const *str);

int	check_neg(const char *str)
{
	int	count;

	count = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		str++;
	}
	if (count % 2 == 0)
		return (0);
	else
		return (1);
}

int	ft_atoi(char const *str)
{
	int long	value;

	while (*str <= ' ' && (*str != '\a' && *str != '\b'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (check_neg(str) == 1)
		{
			while (*str < '0' || *str > '9')
				str++;
			value = convert(str);
			value = value * (-1);
		}
		else
		{
			while (*str < '0' || *str > '9')
				str++;
			value = convert(str);
		}
	}
	else
		value = convert(str);
	return (value);
}

static int long	convert(char const *str)
{
	int long	value;

	value = 0;
	while (*str != '\0' && ft_isdigit(*str) > 0)
	{
		value *= 10;
		value += (*str - 48);
		str += 1;
	}
	if (value > 2147483647 || value < -2147483648)
		return (0);
	return (value);
}
