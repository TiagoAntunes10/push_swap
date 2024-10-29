/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:00:51 by tialbert          #+#    #+#             */
/*   Updated: 2024/02/13 14:41:27 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/ft_printf.h"

void	swap_cond(t_list **stc_a, t_list **stc_b, char *cmd);
void	rotate_cond(t_list **stc_a, t_list **stc_b, char *cmd);
void	swap_ss(t_list **lst_a, t_list **lst_b);
void	rotate_ss(t_list **lst_a, t_list **lst_b);
void	rev_rotate_ss(t_list **lst_a, t_list **lst_b);
void	push_cond(t_list **stc_a, t_list **stc_b, char *cmd);
void	free_array(char **arr);
void	print_error(t_list **lst_a, t_list **lst_b, char **arr);
int		ft_nb_len(int nb);
int		ft_cont_alpha(char *str);
int		check_arg(char *str, int nb);
void	handle_free(char **argv, int argc, t_list **lst);
int		checker(t_list **stc_a);
int		check_duplicates(t_list **stc);
