/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:52:18 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 13:52:20 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_list	*save;

	if (stack->size_b == 0)
		return ;
	save = (stack->stack_b);
	(stack->stack_b) = (stack->stack_b)->next;
	save->next = (stack->stack_a);
	(stack->stack_a) = save;
	stack->size_a += 1;
	stack->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_list	*save;

	if (stack->size_a == 0)
		return ;
	save = (stack->stack_a);
	(stack->stack_a) = (stack->stack_a)->next;
	save->next = (stack->stack_b);
	(stack->stack_b) = save;
	stack->size_a -= 1;
	stack->size_b += 1;
	write(1, "pb\n", 3);
}

void	ra(t_list **stack_A)
{
	t_list	*save;
	t_list	*last;

	if ((*stack_A)->next == NULL)
		return ;
	save = *stack_A;
	last = ft_lstlast(*stack_A);
	*stack_A = (*stack_A)->next;
	last->next = save;
	save->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_B)
{
	t_list	*save;
	t_list	*last;

	save = *stack_B;
	last = ft_lstlast(*stack_B);
	*stack_B = (*stack_B)->next;
	last->next = save;
	save->next = NULL;
	write(1, "rb\n", 3);
}
