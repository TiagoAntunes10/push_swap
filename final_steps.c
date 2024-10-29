/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:12:10 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/11 16:13:38 by tialbert         ###   ########.fr       */
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

static void	sum_cost(t_list *lst, t_list **stc_a, int size_b)
{
	t_list	*lst_a;
	int		size_a;

	lst_a = *stc_a;
	size_a = ft_lstsize(*stc_a);
	while (lst_a->next != NULL)
	{
		if (lst->data > lst_a->data && lst->data < lst_a->next->data)
		{
			price_sep(lst, lst_a->next, size_b, size_a);
			return ;
		}
		lst_a = lst_a->next;
	}
	if (lst->data < (*stc_a)->data && lst->data > lst_a->data)
	{
		lst->fut_pos = 0;
		return ;
	}
	lst->fut_pos = find_min(*stc_a);
	max_min_sep(lst, size_b, size_a);
}

static int	finish_stc(t_list **stc_b, t_list **stc_a)
{
	t_list	*lst;
	int		min;
	int		pos;

	get_cost(stc_a);
	get_cost(stc_b);
	lst = (*stc_b);
	if (ft_lstsize(*stc_a) >= ft_lstsize(*stc_b))
		min = ft_lstsize(*stc_a);
	else
		min = ft_lstsize(*stc_b);
	pos = 0;
	while (lst != NULL)
	{
		sum_cost(lst, stc_a, ft_lstsize(*stc_b));
		if (lst->price < min)
		{
			min = lst->price;
			pos = lst->position;
		}
		lst = lst->next;
	}
	return (pos);
}

static void	finish_push_stc(t_list **stc_b, t_list **stc_a, int pos)
{
	int	fut;
	int	size_a;
	int	size_b;

	fut = get_fut(stc_b, pos);
	size_a = ft_lstsize(*stc_a);
	size_b = ft_lstsize(*stc_b);
	if (pos > size_b / 2 && fut > size_a / 2)
		rev_rotate_both(stc_a, stc_b, fut, pos);
	else if (pos <= size_b / 2 && fut <= size_a / 2)
		rotate_both(stc_a, stc_b, fut, pos);
	else if (pos > size_b / 2 && fut <= size_a / 2)
		up_a_down_b(stc_a, stc_b, fut, pos);
	else if (pos <= size_b / 2 && fut > size_a / 2)
		down_a_up_b(stc_a, stc_b, fut, pos);
	push(stc_a, stc_b, 'a');
}

void	final_stc(t_list **stc_a, t_list **stc_b)
{
	int	pos;

	while (*stc_b != NULL)
	{
		pos = finish_stc(stc_b, stc_a);
		finish_push_stc(stc_b, stc_a, pos);
	}
	top_value(stc_a);
}
