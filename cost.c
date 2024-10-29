/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:07:28 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/09 23:29:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_cost(t_list **stc)
{
	t_list	*lst;
	int		i;
	int		size;

	i = 0;
	lst = *stc;
	size = ft_lstsize(*stc);
	while (lst != NULL)
	{
		if (i > size / 2)
			lst->price = size - i;
		else
			lst->price = i;
		lst->position = i;
		i++;
		lst = lst->next;
	}
}

static void	sum_cost(t_list *lst, t_list **stc_b, int size_a)
{
	t_list	*lst_b;
	int		size_b;

	lst_b = *stc_b;
	size_b = ft_lstsize(*stc_b);
	while (lst_b->next != NULL)
	{
		if (lst->data < lst_b->data && lst->data > lst_b->next->data)
		{
			price_sep(lst, lst_b->next, size_a, size_b);
			return ;
		}
		lst_b = lst_b->next;
	}
	if (lst->data > (*stc_b)->data && lst->data < lst_b->data)
	{
		lst->fut_pos = 0;
		return ;
	}
	lst->fut_pos = find_max(*stc_b);
	max_min_sep(lst, size_a, size_b);
}

int	calc_cost(t_list **stc_a, t_list **stc_b)
{
	t_list	*lst;
	int		min;
	int		pos;

	get_cost(stc_a);
	get_cost(stc_b);
	lst = (*stc_a);
	if (ft_lstsize(*stc_a) >= ft_lstsize(*stc_b))
		min = ft_lstsize(*stc_a);
	else
		min = ft_lstsize(*stc_b);
	pos = 0;
	while (lst != NULL)
	{
		sum_cost(lst, stc_b, ft_lstsize(*stc_a));
		if (lst->price < min)
		{
			min = lst->price;
			pos = lst->position;
		}
		lst = lst->next;
	}
	return (pos);
}
