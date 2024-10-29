/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:44:44 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 15:00:39 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_array(char **arr);
static t_list	**create_lst(char **argv, int argc);
static t_list	**sort_stc(t_list **stc_a, t_list **stc_b, int size);

int	main(int argc, char **argv)
{
	t_list	**stc_a;
	t_list	**stc_b;
	char	**stc;

	if (argc == 1)
		exit (1);
	else if (argc == 2)
		stc = ft_split(argv[1], ' ');
	if (argc == 2)
	{
		stc_a = create_lst(stc, argc);
		free_array(stc);
	}
	else
		stc_a = create_lst(++argv, argc);
	stc_b = NULL;
	if (check_duplicates(stc_a) == 1)
		print_error(stc_a, stc_b, NULL);
	stc_b = sort_stc(stc_a, stc_b, ft_lstsize(*stc_a));
	if (stc_b != NULL)
		final_stc(stc_a, stc_b);
	checker(stc_a, stc_b);
	ft_lstclear(stc_a);
	ft_lstclear(stc_b);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static t_list	**create_lst(char **argv, int argc)
{
	t_list	**lst;
	t_list	*node;
	int		nb;
	int		i;

	if (*argv == NULL)
		print_error(NULL, NULL, argv);
	lst = malloc(sizeof(t_list *));
	if (lst == NULL)
		print_error(NULL, NULL, NULL);
	*lst = NULL;
	i = 0;
	while (*argv != NULL)
	{
		nb = ft_atoi(*argv);
		if (check_arg(*argv, nb) == 1)
			handle_free(argv - i, argc, lst);
		node = ft_lstnew(nb);
		if (node == NULL)
			return (lst);
		argv++;
		i++;
		ft_lstadd_back(lst, node);
	}
	return (lst);
}

static void	transfer_stc(t_list **stc_a, t_list **stc_b)
{
	int	pos;

	pos = calc_cost(stc_a, stc_b);
	push_stc(stc_a, stc_b, pos);
}

static t_list	**sort_stc(t_list **stc_a, t_list **stc_b, int size)
{
	if (checker(stc_a, stc_b) == 1)
		return (NULL);
	if (size == 2)
	{
		swap(stc_a, 'a');
		return (NULL);
	}
	while (ft_lstsize(*stc_a) > 3)
	{
		if (stc_b == NULL)
		{
			stc_b = malloc(sizeof(t_list *));
			if (stc_b == NULL)
				print_error(stc_a, NULL, NULL);
			*stc_b = NULL;
			start_stc(stc_a, stc_b);
		}
		if (checker(stc_a, stc_b) == 1)
			return (stc_b);
		if (ft_lstsize(*stc_a) > 3)
			transfer_stc(stc_a, stc_b);
	}
	sort_small(stc_a);
	return (stc_b);
}
