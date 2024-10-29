/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_cross_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:07:42 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 14:42:24 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	push(t_list **lst_rec, t_list **lst_giv)
{
	t_list	*lst_tmp;

	if ((*lst_giv) == NULL)
		return ;
	lst_tmp = (*lst_giv)->next;
	ft_lstadd_front(lst_rec, (*lst_giv));
	*lst_giv = lst_tmp;
}

void	push_cond(t_list **stc_a, t_list **stc_b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push(stc_a, stc_b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push(stc_b, stc_a);
	else
		print_error(stc_a, stc_b, NULL);
}
