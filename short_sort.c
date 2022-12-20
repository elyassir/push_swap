/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:26:47 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 11:01:53 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stack_A)
{
	if (stack_A == NULL)
		return (-1);
	while (stack_A->next != NULL)
	{
		if (stack_A->content > stack_A->next->content)
			return (0);
		stack_A = stack_A->next;
	}
	return (1);
}

void	sort_three(t_list **stack_A)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack_A)->content;
	num2 = (*stack_A)->next->content;
	num3 = (*stack_A)->next->next->content;
	if (num1 > num3 && num3 > num2)
		ra(stack_A);
	else if (num1 > num2 && num2 > num3)
	{
		sa(*stack_A, 2);
		rra(stack_A);
	}
	else if (num1 < num3 && num1 > num2)
		sa(*stack_A, 2);
	else if (num1 > num3 && num1 < num2)
		rra(stack_A);
	else if (num1 < num2 && num2 > num3)
	{
		rra(stack_A);
		sa(*stack_A, 2);
	}
}

int	find_small(t_list *stack_a, int size_a)
{
	int	small;
	int	i;

	i = 0;
	small = stack_a->content;
	while (i < size_a)
	{
		if (small > stack_a->content)
			small = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	return (small);
}

void	sort_five(t_stack *stack)
{
	t_list	*helper;
	int		small;
	int		place_of_small;

	place_of_small = 0;
	while (stack->size_a > 3)
	{
		small = find_small(stack->stack_a, stack->size_a);
		place_of_small = 0;
		helper = stack->stack_a;
		while (helper->content != small && place_of_small++ != -1)
			helper = helper->next;
		if (place_of_small > stack->size_a / 2)
			while ((stack->stack_a)->content != small)
				rra(&stack->stack_a);
		else
			while ((stack->stack_a)->content != small)
				ra(&stack->stack_a);
		pb(stack);
	}
	sort_three(&stack->stack_a);
	while (stack->size_b > 0)
		pa(stack);
}

void	ft_bad_sort(int *tmp, int size_a)
{
	int	i;
	int	data;

	i = 0;
	while (i < size_a - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			data = tmp[i + 1];
			tmp[i + 1] = tmp[i];
			tmp[i] = data;
			i = 0;
		}
		else
			i++;
	}
}
