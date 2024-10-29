/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:07:39 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/09 12:09:35 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	del(void *content);

void	ft_lstclear(t_list **lst)
{
	t_list	*lst_next;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		lst_next = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = lst_next;
	}
	free(lst);
}

/*
void	del(void *content)
{
	free(content);
}

#include <stdio.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*new;
	t_list	*current;

	lst = malloc(sizeof(t_list **));
	lst1 = ft_lstnew("aaaaaa");
	ft_lstadd_back(lst, lst1);
	lst2 = ft_lstnew("bbbbbb");
	ft_lstadd_back(lst, lst2);
	lst3 = ft_lstnew("ccccccc");
	ft_lstadd_back(lst, lst3);
	new = ft_lstnew("dddddd");
	ft_lstadd_back(lst, new);
	current = *lst;
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
	ft_lstclear(lst, del);
	current = *lst;
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
}*/
