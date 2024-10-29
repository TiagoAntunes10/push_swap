/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:58:38 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/03 16:29:58 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_list **stc)
{
	int		top;
	int		mid;
	int		bot;

	top = (*stc)->data;
	mid = (*stc)->next->data;
	bot = (*stc)->next->next->data;
	if (top > mid && top > bot && mid < bot)
		rotate(stc, 'a');
	else if (top > mid && top < bot && mid < bot)
		swap(stc, 'a');
	else if (top > mid && top > bot && mid > bot)
	{
		rotate(stc, 'a');
		swap(stc, 'a');
	}
	else if (top < mid && top > bot && mid > bot)
		rev_rotate(stc, 'a');
	else if (top < mid && top < bot && mid > bot)
	{
		swap(stc, 'a');
		rotate(stc, 'a');
	}
}

void	push_stc(t_list **stc_a, t_list **stc_b, int pos)
{
	int	fut;
	int	size_a;
	int	size_b;

	fut = get_fut(stc_a, pos);
	size_a = ft_lstsize(*stc_a);
	size_b = ft_lstsize(*stc_b);
	if (pos > size_a / 2 && fut > size_b / 2)
		rev_rotate_both(stc_a, stc_b, pos, fut);
	else if (pos <= size_a / 2 && fut <= size_b / 2)
		rotate_both(stc_a, stc_b, pos, fut);
	else if (pos > size_a / 2 && fut <= size_b / 2)
		down_a_up_b(stc_a, stc_b, pos, fut);
	else if (pos <= size_a / 2 && fut > size_b / 2)
		up_a_down_b(stc_a, stc_b, pos, fut);
	push(stc_b, stc_a, 'b');
}
