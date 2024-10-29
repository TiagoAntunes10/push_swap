/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:35:41 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/09 11:52:29 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->data = data;
	lst->price = 0;
	lst->position = 0;
	lst->fut_pos = 0;
	lst->next = NULL;
	return (lst);
}

/*
#include <stdio.h>

int	main(void)
{
	struct s_list	lst;
	t_list			*lst1;
	int		*str;

	str = "ashdb";
	lst1 = &lst;
	lst1 = ft_lstnew(str);
	printf("%s\n", (int		 *) (*lst1).data);
}*/
