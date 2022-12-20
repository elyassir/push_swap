/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:35:43 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 11:19:26 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_normal_sort_b(t_stack *stack, int *tmp)
{
	t_list	*helper;
	int		bigger;
	int		place_of_bigger;
	int		_2big;

	place_of_bigger = 0;
	while (stack->size_b > 1)
	{
		bigger = tmp[stack->size_b - 1];
		_2big = tmp[stack->size_b - 2];
		place_of_bigger = 0;
		helper = stack->stack_b;
		while (helper->content != bigger)
		{
			place_of_bigger++;
			helper = helper->next;
		}
		ft_put_big_to_top(stack, place_of_bigger, bigger, _2big);
	}
	pa(stack);
}

void	sort_100_number_first(t_stack *stack, int *range, int chunck)
{
	int	i;

	i = 0;
	while (i < chunck)
	{
		if (stack->tmp[range[0]] <= (stack->stack_a)->content && \
				stack->tmp[range[1]] >= (stack->stack_a)->content)
		{
			pb(stack);
			i++;
		}
		else
			ra(&stack->stack_a);
	}
}

void	sort_100_number_second(t_stack *stack, int *range_1, \
		int *range_2, int chunck)
{
	int	i;

	i = 0;
	while (i < chunck * 2)
	{
		if ((stack->tmp[range_1[0]] <= (stack->stack_a)->content && \
					stack->tmp[range_1[1]] >= (stack->stack_a)->content) || \
				(stack->tmp[range_2[0]] <= (stack->stack_a)->content && \
				stack->tmp[range_2[1]] >= (stack->stack_a)->content))
		{
			if ((stack->tmp[range_2[0]] <= (stack->stack_a)->content && \
						stack->tmp[range_2[1]] >= (stack->stack_a)->content))
				pb(stack);
			else
			{
				pb(stack);
				if (stack->size_b >= 2)
					rb(&stack->stack_b);
			}
			i++;
		}
		else
			ra(&stack->stack_a);
	}
}

void	sort_100(t_stack *stack, int chunck, int *range, int *range_b)
{
	int	save;

	save = stack->size_a;
	while (stack->size_a != 0)
	{
		if (range[0] >= save || range[1] >= save)
		{
			while (stack->size_a > 0)
				pb(stack);
			break ;
		}
		else if (save == stack->size_a && chunck * 2 < stack->size_a)
		{
			sort_100_number_second(stack, range, range_b, chunck);
			range[1] += chunck * 2;
			range[0] += chunck * 2;
		}
		else
		{
			sort_100_number_first(stack, range, chunck);
			range[1] += chunck;
			range[0] += chunck;
		}
	}
	ft_normal_sort_b(stack, stack->tmp);
}

void	sort_100_number(t_stack *stack)
{
	int	chunck;
	int	range[2];
	int	save_onetime[2];
	int	range_b[2];

	save_onetime[0] = stack->size_a;
	ft_bad_sort(stack->tmp, stack->size_a);
	chunck = 20;
	if (stack->size_a > 150)
		chunck = 50;
	range[1] = chunck - 1;
	range [0] = 0;
	save_onetime[1] = 0;
	range_b[1] = range[1] + chunck;
	range_b[0] = range[0] + chunck;
	sort_100(stack, chunck, range, range_b);
}
