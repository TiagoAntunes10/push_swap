/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:44:57 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/02 09:46:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char stack)
{
	int		tmp;
	t_list	*lst_next;

	lst_next = (*lst)->next;
	tmp = (*lst)->data;
	(*lst)->data = lst_next->data;
	lst_next->data = tmp;
	ft_printf("s%c\n", stack);
}

void	rotate(t_list **lst, char stack)
{
	t_list	*lst_last;
	t_list	*lst_next;

	lst_last = ft_lstlast(*lst);
	lst_next = (*lst)->next;
	lst_last->next = (*lst);
	(*lst)->next = NULL;
	*lst = lst_next;
	ft_printf("r%c\n", stack);
}

void	rev_rotate(t_list **lst, char stack)
{
	t_list	*lst_last;
	t_list	*lst_sec_last;

	lst_last = ft_lstlast(*lst);
	lst_sec_last = (*lst);
	while ((lst_sec_last->next)->next != NULL)
		lst_sec_last = lst_sec_last->next;
	lst_last->next = (*lst);
	lst_sec_last->next = NULL;
	*lst = lst_last;
	ft_printf("rr%c\n", stack);
}
