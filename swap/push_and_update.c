/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molesen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:42:52 by molesen           #+#    #+#             */
/*   Updated: 2022/05/18 11:42:54 by molesen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smallest_number(int *c, int *small, int len, int top_c)
{
	int	i;

	i = top_c;
	*small = c[top_c];	
	while (i < len)
	{
		if (c[i] < *small)
			*small = c[i];
		++i;
	}
}

static void	biggest_number(int *c, int *big, int len, int top_c)
{
	int	i;

	i = top_c;
	*big = c[top_c];
	while (i < len)
	{
		if (c[i] > *big)
			*big = c[i];
		++i;
	}
}

static void	update_big_small(int *c, int *small, int *big)
{
	if (c[0] > *big)
		*big = c[0];
	if (c[0] < *small)
		*small = c[0];
}

static void	update_big_small_value(t_stack *stack, char c)
{
	if (c == 'a')
	{
		
		update_big_small(&stack->a[stack->top_a], &stack->a_small, &stack->a_big);
		if (stack->b_empty == TRUE)
		{
			stack->b_small = 2147483647;
			stack->b_big = -2147483648;
		}
		else if (stack->a[stack->top_a] == stack->b_big)
			biggest_number(stack->b, &stack->b_big, stack->bottom, stack->top_b);
		else if (stack->a[stack->top_a] == stack->b_small)
			smallest_number(stack->b, &stack->b_small, stack->bottom, stack->top_b);
	}
	else
	{
		update_big_small(&stack->b[stack->top_b], &stack->b_small, &stack->b_big);
		if (stack->b[stack->top_b] == stack->a_big)
			biggest_number(stack->a, &stack->a_big, stack->bottom, stack->top_a);
		else if (stack->b[stack->top_b] == stack->a_small)
			smallest_number(stack->a, &stack->a_small, stack->bottom, stack->top_a);
	}
}

/*
	something wrong with this function and pushign to stack a

	use this test case
	ARG="-12 -17 10 24 -47 31 7 -21 -48 -40 -30 -22 38 30 -33 48 -36 -2 11 -43 14 -41 42 5 -9 -42 3 21 46 -32 -1 -45 -8 23 29 -35 36 -46 9 -25 -16 33 -24 43 -44 27 -14 49 -34 -18 -7 41 45 13 50 8 19 32 4 -31 -3 -10 34 -19 -6 -27 25 -39 -28 -49 47 37 28 -23 39 -26 6 -37 -11 1 15 -50 -5 44 -20 35 22 20 16 -13 -15 18 12 0 -29 -38 -4 2 40 26 17"; ./push_swap $ARG | ./checker $ARG

	ARG="-12 -17 10 24 -47 31 7 -21 -48 -40 -30 -22 38 30 -33 48 -36 -2 11 -43 14 -41 42 5 -9 -42 3 21 46 -32"; ./push_swap $ARG

	ARG="-12 -17 10 24 -47 31 7 -21 -48 -40 -30 -22 38 30 -33"; ./push_swap $ARG

*/

static int	calc_push_a_rotation(t_stack *stack, int nbr, int top_c)
{
	int	i;
	int	save;
//	static int first = TRUE;
	//static int temp_big_numb = FALSE;

	i = top_c;
	save = stack->bottom + 1;
	/*
	if (stack->a[i] < nbr && stack->a[stack->bottom - 1] > nbr && c == 'a')
		save = i - top_c;
	else if (stack->b[i] < nbr && stack->b[stack->bottom - 1] > nbr && c == 'b')
		save = i - top_c;*/
	//ft_printf("save: %d, median: %d, median_nbr: %d, bottom median: %d\n", save, stack->median, stack->median_nbr, (((stack->bottom - top_c) / 2) + ((stack->bottom - top_c) % 2)));
	/*
		use ordered_small and ordered_big somehow
	*/
	//ft_printf("stack->ordered_small: %d, ordered_big: %d\n", stack->ordered_small, stack->ordered_big);
				//exit(0);
	//if (stack->a[stack->top_a] == stack->ordered_small || (stack->a[stack->top_a] == stack->a_small && stack->ordered_small > stack->ordered_big))
	//	save = 0;
	//else if (stack->a[stack->top_a] < nbr && c == 'a' && (stack->a[stack->top_a] == stack->ordered_small || (stack->a[stack->top_a] == stack->a_small && stack->ordered_small > stack->ordered_big)))
	//	save = 0;
	// ft_printf("stack->first_small: %d\n", stack->first_small);
	// if (first == TRUE || stack->first_small == TRUE)
	// {
	// 	if (first == TRUE)
	// 		temp_big_numb = nbr;
	// 	save = 0;
	// 	first = FALSE;
	// 	solve_and_print(stack, "pa");
	// }
	// else
	// {
	while (i < stack->bottom)
	{
		if (stack->ordered_small > nbr && stack->a[i] == stack->ordered_small)
		{
			save = i - top_c;
			break ;
		}
		if (stack->a[i] > nbr && i == top_c && stack->a[i] == stack->ordered_small)// might remove this >> (nbr > stack->a_big && stack->a[i] == stack->a_big)
		{
			save = i - top_c;
		}
		// else if (stack->a[i] < nbr && stack->a[i] == temp_big_numb && i + 1 != stack->bottom)
		// {
		// 	ft_printf("HERE3\n");
		// 	save = i - top_c;
		// 	break ;
		// }
		else if (stack->a[i] > nbr && stack->a[i - 1] < nbr)// might remove this >> (nbr > stack->a_big && stack->a[i] == stack->a_big)
		{
			save = i - top_c;
		}
		++i;
	}
//	}
	// if (stack->bottom - 1 == stack->top_b)
	// {	
	// 	first_small = FALSE;
	// }
	//ft_printf("\nsave: %d, div: %d, nbr: %d\n", save, (((stack->bottom - top_c) / 2) + ((stack->bottom - top_c) % 2)), nbr);
	if (save == stack->bottom + 1)
		return (ERROR);
	if (save + 1 >= (((stack->bottom - top_c) / 2) + ((stack->bottom - top_c) % 2)))
		return (TRUE);
	return (FALSE);
}

/*something is wrong with above rotation logic*/

static void	push_and_update_helper(t_stack *stack, char c, int d)
{
	if (c == 'a')
	{
		d = calc_push_a_rotation(stack, stack->b[stack->top_b], stack->top_a);
		if (d == FALSE)
		{
			if (stack->ordered_big < stack->b[stack->top_b] && stack->ordered_small <= stack->ordered_big)
			{
				while (stack->a[stack->bottom - 1] != stack->ordered_big)
				{
					solve_and_print(stack, "ra");
				}
			}
			else if (stack->ordered_small > stack->b[stack->top_b] && stack->ordered_small <= stack->ordered_big)
			{
				while (stack->a[stack->top_a] != stack->ordered_small)
				{
					solve_and_print(stack, "ra");
				}
			}
			else
			{
				while (!(stack->a[stack->top_a] > stack->b[stack->top_b] && stack->a[stack->bottom - 1] < stack->b[stack->top_b]))
				{
					solve_and_print(stack, "ra");
				}
			}
			solve_and_print(stack, "pa");
		}
		else if (d == TRUE)
		{
			if (stack->ordered_big < stack->b[stack->top_b] && stack->ordered_small <= stack->ordered_big)
			{
				while (stack->a[stack->bottom - 1] != stack->ordered_big)
					solve_and_print(stack, "rra");
			}
			else if (stack->ordered_small > stack->b[stack->top_b] && stack->ordered_small <= stack->ordered_big)
			{
				while (stack->a[stack->top_a] != stack->ordered_small)
					solve_and_print(stack, "rra");
			}
			else
			{
				// if (stack->a[stack->top_a] == stack->ordered_big)
				// 	while (stack->a[stack->bottom - 1] != stack->ordered_small)
				// 		solve_and_print(stack, "rra");
				while (!((stack->a[stack->bottom - 1] < stack->b[stack->top_b] && stack->a[stack->top_a] > stack->b[stack->top_b])))// || stack->a[stack->bottom - 1] == stack->a_small) && stack->a[stack->top_a] < stack->b[stack->top_b]))//stack->a[stack->bottom - 1] > stack->b[stack->top_b])
					solve_and_print(stack, "rra");
			}
			solve_and_print(stack, "pa");
		}
		else
		{
			solve_and_print(stack, "pa");
		}
		if (stack->ordered_small > stack->a[stack->top_a])
			stack->ordered_small = stack->a[stack->top_a];
		if (stack->ordered_big < stack->a[stack->top_a])
		{
			int i = stack->top_a;
			stack->ordered_big = stack->a[stack->top_a];
			while (stack->a[i] < stack->a[i + 1])
			{
				stack->ordered_big = stack->a[i + 1];
				++i;
			}
		}
		if (stack->top_b == stack->bottom)//means one element left
		{
			//stack->b_empty = TRUE;
			stack->b_small = 2147483647;
			stack->b_big = -2147483648;
		}
	}
	else
	{
		// if (stack->b[stack->top_b] > stack->a[stack->top_a] && stack->b[stack->top_b + 1] < stack->a[stack->top_a])
		// {
		// 	solve_and_print(stack, "pb");
		// 	update_big_small_value(stack, c);
		// 	switch_stacks(stack, 'b');
		// }
		// else
		// {
			// if (stack->b_small > stack->a[stack->top_a] || \
			// stack->b_big < stack->a[stack->top_a])
			// {
			// 	stack_rotate_init(stack, stack->b, stack->b_small, 'b');
			// }
			// else
			// {
			// 	d = calc_rr_or_rrr(stack, stack->a[stack->top_a], stack->top_b, 'b');
			// 	if (d == FALSE && stack->b_empty == FALSE)// && stack->a[stack->top_a] < stack->b_big && stack->b_big > stack->b_small)
			// 	{	
			// 		while (!((stack->b[stack->bottom - 1] > stack->a[stack->top_a] && stack->b[stack->top_b] < stack->a[stack->top_a])))//!((stack->b[stack->bottom - 1] > stack->a[stack->top_a])))// || stack->b[stack->bottom - 1] == stack->b_small) && stack->b[stack->top_b] < stack->a[stack->top_a]))//stack->b[stack->bottom - 1] < stack->a[stack->top_a] || (stack->b[stack->bottom - 1] > stack->a[stack->top_a] && stack->b[stack->top_b] > stack->a[stack->top_a]))
			// 			solve_and_print(stack, "rb");
			// 	}else if (d == TRUE && stack->b_empty == FALSE)// && stack->a[stack->top_a] < stack->b_big && stack->b_big > stack->b_small)
			// 	{
			// 		while (!((stack->b[stack->bottom - 1] > stack->a[stack->top_a] && stack->b[stack->top_b] < stack->a[stack->top_a])))//!((stack->b[stack->bottom - 1] > stack->a[stack->top_a])))// || stack->b[stack->bottom - 1] == stack->b_small) && stack->b[stack->top_b] < stack->a[stack->top_a]))//stack->b[stack->bottom - 1] < stack->a[stack->top_a] || (stack->b[stack->bottom - 1] > stack->a[stack->top_a] && stack->b[stack->top_b] > stack->a[stack->top_a]))
			// 		{
			// 			solve_and_print(stack, "rrb");
			// 		}
			// 	}
			// }
			solve_and_print(stack, "pb");
			//stack->top_b != stack->bottom - 1 is important because we don't want to do these on the first push!!! dont delete!!!
			/*if (stack->top_b != stack->bottom - 1 && stack->b[stack->top_b] < stack->b[stack->top_b + 1] && stack->b[stack->top_b] < stack->b[stack->top_b + 2])//(stack->b[stack->top_b] < stack->b[stack->bottom - 1] || (stack->b[stack->top_b] < stack->b[stack->top_b + 1] && stack->b[stack->top_b] < stack->b[stack->top_b + 2])))
			{
				solve_and_print(stack, "rb");
			}
			if (stack->top_b != stack->bottom - 1 && stack->b[stack->top_b] < stack->b[stack->top_b + 1])
			{
				switch_stacks(stack, 'b');
			}*/
	//	}
		if (stack->b_small > stack->b_big)//means stack is empty
		{
			//stack->b_empty = FALSE;
			stack->b_small = stack->b[stack->bottom - 1];
			stack->b_big = stack->b[stack->top_b];
		}
	}
}

void	push_and_update(t_stack *stack, char c)
{
	if (c == 'a')
	{
		push_and_update_helper(stack, c, 0);
		update_big_small_value(stack, c);
	}
	else
	{
		push_and_update_helper(stack, c, 0);
		update_big_small_value(stack, c);
	}
	// maybe makes most sense here to check if stack b is sorted or not?? or maybe after moving stuff?
}