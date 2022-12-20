/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:27:24 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 13:52:41 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_A, int size_a)
{
	int	tmp;

	if (size_a < 2)
		return ;
	tmp = (stack_A)->content;
	stack_A->content = (stack_A)->next->content;
	stack_A->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_B, int size_b)
{
	int	tmp;

	if (size_b < 2)
		return ;
	tmp = (stack_B)->content;
	stack_B->content = (stack_B)->next->content;
	stack_B->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_A, t_list *stack_B, int size_A, int size_B)
{
	sb(stack_B, size_B);
	sa(stack_A, size_A);
	write(1, "ss\n", 3);
}
