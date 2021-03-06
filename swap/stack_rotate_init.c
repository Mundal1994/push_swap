/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:23:03 by molesen           #+#    #+#             */
/*   Updated: 2022/05/18 10:23:04 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	stack a or b in focus	*/

void	solve_and_print(t_stack *stack, char *str)
{
	solve_stack(stack, str);
	if (stack->visual == TRUE)
	{
		make_visuals(stack, FALSE, str);
	}
	else
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
}

/*	calculates quickest way to get a specific number to be at the bottom	*/

static int	rotate_based_on_nbr(t_stack *stack)
{
	int	i;
	int	save;

	i = stack->top_a;
	save = stack->bottom + 1;
	while (i < stack->bottom)
	{
		if (stack->a[i] == stack->a_big)
		{
			save = i - stack->top_a;
			break ;
		}
		++i;
	}
	if (save == stack->bottom + 1)
		return (ERROR);
	if (save + 1 >= (((stack->bottom - stack->top_a) / 2) + \
		((stack->bottom - stack->top_a) % 2)))
		return (TRUE);
	return (FALSE);
}

/*	rotates specified stack so biggest or smallest number is at the bottom	*/

void	stack_rotate_init(t_stack *stack)
{
	int	double_r;

	double_r = rotate_based_on_nbr(stack);
	if (double_r == FALSE)
		while (stack->a[stack->bottom - 1] < stack->a[stack->top_a])
			solve_and_print(stack, "ra");
	else if (double_r == TRUE)
		while (stack->a[stack->bottom - 1] < stack->a[stack->top_a])
			solve_and_print(stack, "rra");
}
