/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_mult_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:25:31 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/12 21:36:20 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_ss(t_list **lst_a, t_list **lst_b)
{
	int		tmp;
	t_list	*lst_next_a;
	t_list	*lst_next_b;

	lst_next_a = (*lst_a)->next;
	tmp = (*lst_a)->data;
	(*lst_a)->data = lst_next_a->data;
	lst_next_a->data = tmp;
	if ((*lst_b) != NULL && (*lst_b)->next != NULL)
	{
		lst_next_b = (*lst_b)->next;
		tmp = (*lst_b)->data;
		(*lst_b)->data = lst_next_b->data;
		lst_next_b->data = tmp;
	}
}

void	rotate_ss(t_list **lst_a, t_list **lst_b)
{
	t_list	*lst_last_a;
	t_list	*lst_next_a;
	t_list	*lst_last_b;
	t_list	*lst_next_b;

	lst_last_a = ft_lstlast(*lst_a);
	lst_next_a = (*lst_a)->next;
	lst_last_a->next = (*lst_a);
	(*lst_a)->next = NULL;
	*lst_a = lst_next_a;
	if ((*lst_b) != NULL && (*lst_b)->next != NULL)
	{
		lst_last_b = ft_lstlast(*lst_b);
		lst_next_b = (*lst_b)->next;
		lst_last_b->next = (*lst_b);
		(*lst_b)->next = NULL;
		*lst_b = lst_next_b;
	}
}

void	rev_rotate_ss(t_list **lst_a, t_list **lst_b)
{
	t_list	*lst_last_a;
	t_list	*lst_sec_last_a;
	t_list	*lst_last_b;
	t_list	*lst_sec_last_b;

	lst_last_a = ft_lstlast(*lst_a);
	lst_sec_last_a = (*lst_a);
	while ((lst_sec_last_a->next)->next != NULL)
		lst_sec_last_a = lst_sec_last_a->next;
	lst_last_a->next = (*lst_a);
	lst_sec_last_a->next = NULL;
	*lst_a = lst_last_a;
	if ((*lst_b) != NULL && (*lst_b)->next != NULL)
	{
		lst_last_b = ft_lstlast(*lst_b);
		lst_sec_last_b = (*lst_b);
		while ((lst_sec_last_b->next)->next != NULL)
			lst_sec_last_b = lst_sec_last_b->next;
		lst_last_b->next = (*lst_b);
		lst_sec_last_b->next = NULL;
		*lst_b = lst_last_b;
	}
}
