/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:39:13 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 11:39:35 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **s, int m)
{
	m--;
	while (m >= 0)
	{
		free(s[m]);
		m--;
	}
	free(s);
	return ;
}

void	ft_atoi_check(char *str)
{
	int		i;
	long	number;
	int		signe;

	i = 0;
	signe = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (signe > 0 && number > 2147483647)
			error_and_exit();
		if (signe < 0 && number > 2147483648)
			error_and_exit();
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (signe > 0 && number > 2147483647)
		error_and_exit();
	if (signe < 0 && number > 2147483648)
		error_and_exit();
}

void	cheack_max_min(char **av, int ac)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		j = -1;
		while (split[++j])
			ft_atoi_check(split[j]);
		free_split(split, j);
	}
}

void	cheack_non_num(int ac, char **av)
{
	int	j;

	while (--ac != 0)
	{
		j = -1;
		while (av[ac][++j])
		{
			while (av[ac][j] <= ' ' && av[ac][j] != '\0')
				j++;
			if (av[ac][j] == '\0')
				break ;
			if ((av[ac][j] == '-' || av[ac][j] == '+'))
				if (av[ac][++j] == '\0' || !(av[ac][j] >= '0' \
							&& av[ac][j] <= '9'))
					error_and_exit();
			while ((av[ac][j] >= '0' && av[ac][j] <= '9'))
				j++;
			if (av[ac][j] == '\0')
				break ;
			if (!(av[ac][j] >= '0' && av[ac][j] <= '9') && av[ac][j] > 32)
				error_and_exit();
		}
	}
}
