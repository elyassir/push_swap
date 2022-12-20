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
int ft_is_sorted(int *array, int size)
{
	int i = -1;
	while (++i < size - 1)
		if (array[i] > array[i + 1])
			return (1);
	return (0);
}
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	int i = -1;
	ac--;
	int *array = malloc((ac) * sizeof(int ));
	
	while (++i < ac)
		array[i] = ft_atoi(av[i + 1]);
	printf("%d\n", ft_is_sorted(array, ac));
}
