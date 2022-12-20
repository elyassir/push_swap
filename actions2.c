/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:51:50 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 13:52:48 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_B, t_list **stack_A)
{
	rb(stack_B);
	ra(stack_A);
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_A)
{
	t_list	*current;
	t_list	*save_last;

	current = *stack_A;
	while (current->next->next != NULL)
		current = current->next;
	save_last = current->next;
	save_last->next = *stack_A;
	*stack_A = save_last;
	current->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_B)
{
	t_list	*current;
	t_list	*save_last;

	current = *stack_B;
	while (current->next->next != NULL)
		current = current->next;
	save_last = current->next;
	save_last->next = *stack_B;
	*stack_B = save_last;
	current->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_A, t_list **stack_B)
{
	rra(stack_A);
	rrb(stack_B);
	write(1, "rrr\n", 4);
}
