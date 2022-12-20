/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:11 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 11:38:49 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_my_split(t_stack *stack, char **av, int ac)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		j = -1;
		while (split[++j])
			ft_lstadd_back(&(stack)->stack_a, ft_lstnew(ft_atoi(split[j])));
		(stack)->size_a += j;
		free_split(split, j);
	}
}

void	ft_fill(t_stack *stack, int ac, char **av)
{
	char	**split;
	int		i;
	int		size_tmp;
	int		j;

	i = 0;
	size_tmp = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		if (split == NULL)
		{
			free(stack->tmp);
			error_and_exit();
		}
		j = 0;
		while (split[j])
			stack->tmp[size_tmp++] = ft_atoi(split[j++]);
		free_split(split, j);
	}
}

int	ft_count(int ac, char **av)
{
	char	**split;
	int		i;
	int		j;
	int		size_tmp;

	i = 0;
	size_tmp = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		if (split == NULL)
			error_and_exit();
		j = 0;
		while (split[j])
			j++;
		size_tmp += j;
		free_split(split, j);
	}
	return (size_tmp);
}

void	dup_(t_stack *stack, int ac, char **av)
{
	int		i;
	int		j;
	int		num;
	int		size_tmp;

	size_tmp = ft_count(ac, av);
	stack->tmp = malloc(size_tmp * sizeof(int));
	if (!stack->tmp)
		error_and_exit();
	ft_fill(stack, ac, av);
	i = -1;
	while (++i < size_tmp - 1)
	{
		num = stack->tmp[i];
		j = i;
		while (++j < size_tmp)
		{
			if (stack->tmp[j] == num)
			{
				free(stack->tmp);
				error_and_exit();
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	cheack_non_num(ac, av);
	cheack_max_min(av, ac);
	dup_(&stack, ac, av);
	ft_my_split(&stack, av, ac);
	if (ft_is_sorted(stack.stack_a) == 1)
	{
		ft_lstclear(&stack.stack_a);
		free(stack.tmp);
		return (0);
	}
	if (stack.size_a == 2)
		sa(stack.stack_a, stack.size_a);
	else if (stack.size_a == 3)
		sort_three(&stack.stack_a);
	else if (stack.size_a == 4 || stack.size_a == 5)
		sort_five(&stack);
	else
		sort_100_number(&stack);
	free(stack.tmp);
}
