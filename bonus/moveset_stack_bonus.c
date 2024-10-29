/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:44:57 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 14:43:25 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap(t_list **lst)
{
	int		tmp;
	t_list	*lst_next;

	if ((*lst) != NULL && (*lst)->next != NULL)
	{
		lst_next = (*lst)->next;
		tmp = (*lst)->data;
		(*lst)->data = lst_next->data;
		lst_next->data = tmp;
	}
}

static void	rotate(t_list **lst)
{
	t_list	*lst_last;
	t_list	*lst_next;

	if ((*lst) != NULL && (*lst)->next != NULL)
	{
		lst_last = ft_lstlast(*lst);
		lst_next = (*lst)->next;
		lst_last->next = (*lst);
		(*lst)->next = NULL;
		*lst = lst_next;
	}
}

static void	rev_rotate(t_list **lst)
{
	t_list	*lst_last;
	t_list	*lst_sec_last;

	if ((*lst) != NULL && (*lst)->next != NULL)
	{
		lst_last = ft_lstlast(*lst);
		lst_sec_last = (*lst);
		while ((lst_sec_last->next)->next != NULL)
			lst_sec_last = lst_sec_last->next;
		lst_last->next = (*lst);
		lst_sec_last->next = NULL;
		*lst = lst_last;
	}
}

void	swap_cond(t_list **stc_a, t_list **stc_b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap(stc_a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap(stc_b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		swap_ss(stc_a, stc_b);
	else
		print_error(stc_a, stc_b, NULL);
}

void	rotate_cond(t_list **stc_a, t_list **stc_b, char *cmd)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(stc_a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(stc_b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rev_rotate(stc_a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rev_rotate(stc_b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rev_rotate_ss(stc_a, stc_b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rotate_ss(stc_a, stc_b);
	else
		print_error(stc_a, stc_b, NULL);
}
