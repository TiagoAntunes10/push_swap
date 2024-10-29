/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:44:44 by tialbert          #+#    #+#             */
/*   Updated: 2024/03/24 10:45:27 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void			free_array(char **arr);
static t_list	**create_lst(char **argv, int argc);
static void		sort_stc(t_list **stc_a);

int	main(int argc, char **argv)
{
	t_list	**stc_a;
	char	**stc;
	int		ele_num;

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
	ele_num = ft_lstsize(*stc_a);
	if (check_duplicates(stc_a) == 1)
		print_error(stc_a, NULL, NULL);
	sort_stc(stc_a);
	if (checker(stc_a) == 0 || ft_lstsize(*stc_a) != ele_num)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(stc_a);
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

static void	sort_stc(t_list **stc_a)
{
	char	*line;
	t_list	**stc_b;

	stc_b = malloc(sizeof(t_list *));
	if (stc_b == NULL)
		print_error(stc_a, NULL, NULL);
	*stc_b = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (line[0] == 's')
			swap_cond(stc_a, stc_b, line);
		else if (line[0] == 'p')
			push_cond(stc_a, stc_b, line);
		else if (line[0] == 'r')
			rotate_cond(stc_a, stc_b, line);
		else
		{
			free(line);
			print_error(stc_a, stc_b, NULL);
		}
		free(line);
		line = get_next_line(0);
	}
	ft_lstclear(stc_b);
}
