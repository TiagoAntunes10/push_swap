/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:12:37 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/11 15:55:56 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_both(t_list **stc_a, t_list **stc_b, int pos, int fut)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stc_a);
	size_b = ft_lstsize(*stc_b);
	while (pos < size_a && fut < size_b)
	{
		rev_rotate_ss(stc_a, stc_b);
		pos++;
		fut++;
	}
	while (pos < size_a)
	{
		rev_rotate(stc_a, 'a');
		pos++;
	}
	while (fut < size_b)
	{
		rev_rotate(stc_b, 'b');
		fut++;
	}
}

void	rotate_both(t_list **stc_a, t_list **stc_b, int pos, int fut)
{
	while (pos > 0 && fut > 0)
	{
		rotate_ss(stc_a, stc_b);
		pos--;
		fut--;
	}
	while (pos > 0)
	{
		rotate(stc_a, 'a');
		pos--;
	}
	while (fut > 0)
	{
		rotate(stc_b, 'b');
		fut--;
	}
}

void	down_a_up_b(t_list **stc_a, t_list **stc_b, int pos, int fut)
{
	int	size_a;

	size_a = ft_lstsize(*stc_a);
	while (pos < size_a)
	{
		rev_rotate(stc_a, 'a');
		pos++;
	}
	while (fut > 0)
	{
		rotate(stc_b, 'b');
		fut--;
	}
}

void	up_a_down_b(t_list **stc_a, t_list **stc_b, int pos, int fut)
{
	int	size_b;

	size_b = ft_lstsize(*stc_b);
	while (fut < size_b)
	{
		rev_rotate(stc_b, 'b');
		fut++;
	}
	while (pos > 0)
	{
		rotate(stc_a, 'a');
		pos--;
	}
}
