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
int main(int ac, char **av)
{
	int i = -1;
	ac--;
	int *array = malloc((ac) * sizeof(int ));
	while (++i < ac)
		array[i] = ft_atoi(av[i + 1]);
	i = 0;
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

	i = -1;
	while (++i < ac)
	{
		printf("%d\n", array[i]);
	}
}
