/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:25:37 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 14:39:53 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_arg(char *str, int nb)
{
	if (*str == 0)
		return (1);
	if (ft_cont_alpha(str) == 1)
		return (1);
	while (ft_isdigit(*str) == 0)
		str++;
	if (ft_strlen(str) > ft_nb_len(nb) && nb == 0)
		return (1);
	return (0);
}

void	handle_free(char **argv, int argc, t_list **lst)
{
	if (argc == 2)
		print_error(lst, NULL, argv);
	else
		print_error(lst, NULL, NULL);
}

int	checker(t_list **stc_a)
{
	t_list	*lst;
	t_list	*stc_next;

	lst = (*stc_a);
	stc_next = lst->next;
	while (stc_next != NULL)
	{
		if (stc_next->data < lst->data)
			return (0);
		else if (stc_next->data == lst->data)
			print_error(stc_a, NULL, NULL);
		lst = lst->next;
		stc_next = lst->next;
	}
	return (1);
}

int	check_duplicates(t_list **stc)
{
	t_list	*lst;
	t_list	*lst_next;
	int		data;

	lst = (*stc);
	while (lst != NULL)
	{
		lst_next = lst->next;
		data = lst->data;
		while (lst_next != NULL)
		{
			if (data == lst_next->data)
				return (1);
			lst_next = lst_next->next;
		}
		lst = lst->next;
	}
	return (0);
}
