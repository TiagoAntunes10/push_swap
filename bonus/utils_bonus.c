/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:36:15 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 14:41:05 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_error(t_list **lst_a, t_list **lst_b, char **arr)
{
	write(2, "Error\n", 6);
	if (lst_b != NULL)
		ft_lstclear(lst_b);
	if (lst_a != NULL)
		ft_lstclear(lst_a);
	if (arr != NULL)
		free_array(arr);
	exit(1);
}

int	ft_nb_len(int nb)
{
	int	l;

	l = 1;
	if (nb < 0)
	{
		nb *= -1;
		l++;
	}
	while (nb / 10 > 0)
	{
		l++;
		nb /= 10;
	}
	return (l);
}

int	ft_cont_alpha(char *str)
{
	int	start_num;

	start_num = 0;
	if (ft_strlen(str) == 1 && ft_isdigit(*str) == 0)
		return (1);
	while (*str != 0)
	{
		if (ft_isalpha(*str) != 0)
			return (1);
		else if (ft_isdigit(*str) != 0)
			start_num++;
		if (start_num > 1 && (*str == ' ' || *str == '\t'))
			return (1);
		else if (*str == '-' && (*(str + 1) == '-' || *(str + 1) == '+'))
			return (1);
		else if (*str == '+' && (*(str + 1) == '-' || *(str + 1) == '+'))
			return (1);
		str++;
	}
	return (0);
}
