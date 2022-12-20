/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:01:15 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 16:01:29 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_big_to_top(t_stack *stack, int place_of_bigger, int bigger, \
		int _2big)
{
	int		i;
	char	choise;

	i = 0;
	if (place_of_bigger > stack->size_b / 2)
		choise = 'r';
	else
		choise = 'b';
	while ((stack->stack_b)->content != bigger)
	{
		if ((stack->stack_b)->content == _2big && i++ != -1)
			pa(stack);
		else
		{
			if (choise == 'r')
				rrb(&stack->stack_b);
			else if (choise == 'b')
				rb(&stack->stack_b);
		}
	}
	pa(stack);
	if (i == 1)
		sa(stack->stack_a, stack->size_a);
}
