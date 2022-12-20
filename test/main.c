#include <stdlib.h>
#include <stdio.h>
int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	number;
	int				signe;

	i = 0;
	signe = 1;
	number = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * signe);
}
void sa(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("sa\n");
}

void rra(int *array, int size)
{
	int i = -1;
	int tmp;
	size--;
    tmp =  array[size];
	while (size > 0)
	{
		array[size ] = array[size - 1];
        size--;
	}
    array[0] = tmp;
	printf("rra\n");
}
void ra(int *array, int size)
{
	int i = 0;
	int tmp;
    tmp =  array[0];
	while (i < size - 1)
	{
		array[i] = array[i + 1];
        i++;
	}
    array[size - 1] = tmp;
	printf("ra\n");
}
int ft_is_sorted(int *array, int size)
{
	int i = -1;
	while (++i < size - 1)
		if (array[i] > array[i + 1])
			return (1);
	return (0);
}
void pb(int *stack_A, int *stack_B, int *size_A, int *size_B)
{
    int tmp;
    tmp = stack_A[0];
    int i = -1;
    while (++i < *size_A - 1)
        stack_A[i] = stack_A[i + 1];
    *size_A -= 1;
    i = *size_B;
    while (i > 0)
    {
        stack_B[i] = stack_B[i - 1];
        i--;
    }
    stack_B[0] = tmp;
    *size_B += 1;
}
void pa(int *stack_A, int *stack_B, int *size_A, int *size_B)
{
    int tmp;
    tmp = stack_B[0];
    int i = -1;
    while (++i < *size_B - 1)
        stack_B[i] = stack_B[i + 1];
    *size_B -= 1;
    i = *size_A;
    while (i > 0)
    {
        stack_A[i] = stack_A[i - 1];
        i--;
    }
    stack_A[0] = tmp;
    *size_A += 1;
}
void ft_sort_three(int *array, int ac)
{
	int not_sorted = ft_is_sorted(array, ac);
	while (not_sorted)
	{
		if (array[0] > array[ac - 1] && array[0] < array[1])
			rra(array, ac);
		else if (array[0] > array[ac - 1] && array[0] > array[1])
			ra(array, ac);
		else
			sa(&array[0], &array[1]);
		not_sorted = ft_is_sorted(array, ac);
	}
}
int main(int ac, char **av)
{
	int i = -1;
	ac--;
	// int *array = malloc((ac) * sizeof(int ));
    int *stack_A = malloc(ac * sizeof(int));
    int *stack_B = malloc(ac * sizeof(int));
    int size_A = ac;
    int size_B = 0;
	while (++i < ac)
		stack_A[i] = ft_atoi(av[i + 1]);
	i = 0;
	if (ac == 3)
		ft_sort_three(stack_A, 3);
	else if (ac == 5)
	{
		pb(stack_A, stack_B, &size_A, &size_B);
		pb(stack_A, stack_B, &size_A, &size_B);
		ft_sort_three(stack_A, 3);
		// sa(&stack_A[0], &stack_A[1]);
		// ra(stack_A, size_A);
		pa(stack_A, stack_B, &size_A, &size_B);
		ra(stack_A, size_A);
		pa(stack_A, stack_B, &size_A, &size_B);
	}
	i = -1;

    printf("Stack A : \n");
    while (++i < size_A)
        printf("%d\n", stack_A[i]);
}


/*
	Find the smallest number in Stack A.-
	Move the smallest number found to the top of Stack A.
	ft_find_small;
	repet ra until the smallest number be the first one then push it to stack b
	reapt until the stack a be empty;
	Push that number to Stack B.
	Repeat steps 1–3 until Stack A is empty.
	Push everything back to stack A once Stack B has all the numbers from biggest to smallest.

*/