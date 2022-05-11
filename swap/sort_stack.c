
#include "push_swap.h"

static void	divide_calculater(t_stack *stack, int *divider)
{
	int	below;
	int	nbr;
	int	i;
	int	j;
	int	count;

	if (stack->bottom < 4)
		below = -2147483648;
	else if (stack->bottom < 50)
		below = stack->bottom - (stack->bottom / 3);
	else
		below = stack->bottom - (stack->bottom / 4);
	i = 0;
	/*ft_putstr("below: ");
	ft_putnbr(below);
	ft_putchar('\n');*/
	while (*divider == -2147483648 && below != -2147483648 && i < stack->bottom)
	{
		nbr = stack->a[i];
		j = 0;
		count = 0;
		while (j < stack->bottom && nbr != -2147483648)
		{
			if (stack->a[j] < nbr)
				++count;
			++j;
		}
		if (count >= below && count <= stack->bottom)
			*divider = nbr;
		++i;
	}
}

void	sort_stack(t_stack *stack)
{
	int	divider;
	int	div;

	divider = -2147483648;
	divide_calculater(stack, &divider);
	ft_putnbr(divider);
	ft_putchar('\n');
	while (check_if_solved(stack, 'p') == ERROR)
	{
		//make a check for if b is in order
		if (stack->a_empty == FALSE && stack->a[stack->top_a] < divider)
		{
			// if a is in order we need to stop this one and start pushing from b to a
			solve_stack(stack, "pa");
			ft_putstr("pa");
		}
		else if (stack->a_empty == FALSE && stack->a[stack->top_a] > stack->a[stack->top_a + 1])
		{
			if (stack->b_empty == FALSE && stack->b[stack->top_b] < stack->b[stack->top_b + 1])
			{
				solve_stack(stack, "ss");
				ft_putstr("ss");
			}
			else
			{
				solve_stack(stack, "sa");
				ft_putstr("sa");
			}
		}
		else if (stack->b_empty == FALSE && stack->b[stack->top_b] < stack->b[stack->top_b + 1])
		{
			solve_stack(stack, "sb");
			ft_putstr("sb");
		}
		ft_putchar('\n');
	}
	ft_putnbr(stack->a[0]);
	ft_putnbr(stack->a[1]);
	ft_putnbr(stack->a[2]);
}

/*

i = 1;
	j = 0;
	int nbr;
	nbr = argc / 2;
	if (argc % 2 > 0)
		nbr += 1;
	 need to use this number to create malloc for stack b

stack sorting logic

collect middle number aka argc / 2

while loop

1. check if stack a is sorted
	if sorted check if b is empty
2. check if stack b is sorted
3. check first two elements of stack a
	if below middle number(try with 1/4) or equal to then move to stack b if following conditions are meet
		the next number in the stack isn't the closest above number with the one we are comparing to
		(ex if we look at 2 but the one below it is 3 then it is sorted correctly - so dont move to stack b if a is sorted or maybe more check if there is one difference)
4. switch top if wrong order (do with both stacks)
5. rotate one way depending on where the next closest to middle number is (check is stack b also should rotate)
6. 

*/