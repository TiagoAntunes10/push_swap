/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:08:14 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/11 11:18:21 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_top(t_list *stc_a)
{
	int	i;
	int	min;
	int	min_pos;

	i = 1;
	min_pos = 0;
	min = stc_a->data;
	stc_a = stc_a->next;
	while (stc_a != NULL)
	{
		if (stc_a->data < min)
		{
			min_pos = i;
			min = stc_a->data;
		}
		i++;
		stc_a = stc_a->next;
	}
	return (min_pos);
}

void	top_value(t_list **stc_a)
{
	int	pos;
	int	size;

	pos = find_top(*stc_a);
	size = ft_lstsize(*stc_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(stc_a, 'a');
	}
	else
	{
		while (pos++ < size)
			rev_rotate(stc_a, 'a');
	}
}

int	find_min(t_list *stc)
{
	int	i;
	int	min;
	int	min_pos;

	i = 1;
	min_pos = 0;
	min = stc->data;
	stc = stc->next;
	while (stc != NULL)
	{
		if (stc->data < min)
		{
			min_pos = i;
			min = stc->data;
		}
		i++;
		stc = stc->next;
	}
	return (min_pos);
}
