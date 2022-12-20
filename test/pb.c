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
#include <stdlib.h>
#include <stdio.h>
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
int main(int ac, char **av)
{
    ac--;
    int *stack_A = malloc(ac * sizeof(int));
    int *stack_B = malloc(ac * sizeof(int));
    int size_A = ac;
    int size_B = 0;
    int i = -1;
    while (++i < size_A)
    {
        stack_A[i] = atoi(av[i + 1]);
    }
    i = -1;
    pb(stack_A, stack_B, &size_A, &size_B);
    pb(stack_A, stack_B, &size_A, &size_B);
    pa(stack_A, stack_B, &size_A, &size_B);
    pa(stack_A, stack_B, &size_A, &size_B);
    printf("Stack A : \n");
    while (++i < size_A)
        printf("%d\n", stack_A[i]);
    printf("Stack B : \n");
    i = -1;
    while (++i < size_B)
        printf("%d\n", stack_B[i]);
}