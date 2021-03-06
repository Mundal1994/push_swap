/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:50:28 by molesen           #+#    #+#             */
/*   Updated: 2022/05/09 19:50:31 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../common/common.h"

void	sort_stack(t_stack *stack);
void	stack_rotate_init(t_stack *stack);
void	push_and_update(t_stack *stack, char c);
void	solve_and_print(t_stack *stack, char *str);
int		longest_list(t_stack *stack);
void	push_to_stack(t_stack *stack, char c);
void	short_stack_logic(t_stack *stack);
int		push_a_rotation_logic(t_stack *stack, int nbr);
void	sort_smallest(t_stack *stack, int calc, int multi);
void	sort_middle(t_stack *stack, int calc, int multi);
void	sort_biggest(t_stack *stack, int calc, int multi);
void	rotate_based_on_calc(t_stack *stack, int calc, char c);
void	make_visuals(t_stack *stack, int first, char *command);
int		check_if_ordered(t_stack *stack);
void	update_values(int *c, int *small, int *big);

#endif
