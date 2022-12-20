/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:02:42 by yel-mass          #+#    #+#             */
/*   Updated: 2022/12/19 11:05:01 by yel-mass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] <= c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (count);
		while (!(s[i] <= c) && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void	get_len_word(char const *s, char c, int *index, int *len_word)
{
	while (s[*index] <= c && s[*index] != '\0')
		*index += 1;
	while (!(s[*index + *len_word] <= c) && s[*index + *len_word])
		*len_word += 1;
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		error_and_exit();
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	size_t			i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	while (i < len && i + start < s_len)
		i++;
	d = malloc((i + 1) * sizeof(char ));
	if (!d)
		error_and_exit();
	i = 0;
	while (i < len && i + start < s_len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**words;
	int		m;
	int		index;
	int		len_word;

	count = count_words(s, c);
	words = malloc((count + 1) * sizeof(char *));
	index = 0;
	m = 0;
	if (!words)
		return (NULL);
	while (m < count)
	{
		len_word = 0;
		get_len_word(s, c, &index, &len_word);
		words[m] = ft_substr(s, index, len_word);
		if (!words[m++])
			return (free_all(words, m));
		index += len_word;
	}
	words[m] = 0;
	return (words);
}
