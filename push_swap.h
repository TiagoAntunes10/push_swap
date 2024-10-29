/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:00:51 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 14:25:18 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "./libft/ft_printf.h"

void	swap(t_list **lst, char stack);
void	swap_ss(t_list **lst_a, t_list **lst_b);
void	rotate(t_list **lst, char stack);
void	rotate_ss(t_list **lst_a, t_list **lst_b);
void	rev_rotate(t_list **lst, char stack);
void	rev_rotate_ss(t_list **lst_a, t_list **lst_b);
void	push(t_list **lst_rec, t_list **lst_giv, char stack);
void	free_array(char **arr);
void	print_error(t_list **lst_a, t_list **lst_b, char **arr);
int		ft_nb_len(int nb);
int		ft_cont_alpha(char *str);
void	start_stc(t_list **stc_a, t_list **stc_b);
int		get_fut(t_list **stc, int pos);
int		check_arg(char *str, int nb);
void	handle_free(char **argv, int argc, t_list **lst);
int		checker(t_list **stc_a, t_list **stc_b);
int		check_duplicates(t_list **stc);
void	sort_small(t_list **stc);
void	push_stc(t_list **stc_a, t_list **stc_b, int pos);
int		calc_cost(t_list **stc_a, t_list **stc_b);
void	max_min_sep(t_list *lst, int size_a, int size_b);
int		find_max(t_list *stc);
void	price_sep(t_list *lst, t_list *lst_b, int size_a, int size_b);
void	final_stc(t_list **stc_a, t_list **stc_b);
void	rev_rotate_both(t_list **stc_a, t_list **stc_b, int pos, int fut);
void	rotate_both(t_list **stc_a, t_list **stc_b, int pos, int fut);
void	down_a_up_b(t_list **stc_a, t_list **stc_b, int pos, int fut);
void	up_a_down_b(t_list **stc_a, t_list **stc_b, int pos, int fut);
void	top_value(t_list **stc_a);
int		find_min(t_list *stc);
