/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:45:48 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 16:09:30 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		*tmp;
}	t_stack;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	sa(t_list *stack_A, int size_a);
void	sb(t_list *stack_B, int size_b);
void	ss(t_list *stack_A, t_list *stack_B, int size_A, int size_B);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_list **stack_A);
void	rb(t_list **stack_B);
void	rr(t_list **stack_B, t_list **stack_A);
void	rra(t_list **stack_A);
void	rrb(t_list **stack_B);
void	rrr(t_list **stack_A, t_list **stack_B);
void	sort_three(t_list **stack_A);
void	sort_100_number(t_stack *stack);
void	sort_five(t_stack *stack);
int		ft_is_sorted(t_list *stack_A);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
void	free_split(char **s, int m);
void	error_and_exit(void);
char	**free_all(char **s, int m);
void	cheack_non_num(int ac, char **av);
void	cheack_max_min(char **av, int ac);
void	ft_bad_sort(int *tmp, int size_a);
void	ft_put_big_to_top(t_stack *stack, int place_of_bigger, \
		int bigger, int _2big);
void	ft_lstclear(t_list **lst);
#endif
