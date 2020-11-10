/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:01:55 by calide-n          #+#    #+#             */
/*   Updated: 2020/11/10 11:46:14 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c || (s[i] != c && s[i + 1] == '\0'))
		{
			count++;
			while (s[i + 1] == c && s[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

static char		**ft_malloc_tab(char **tab, char const *s, char c)
{
	int i;
	int len;
	int x;

	i = 0;
	len = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if (len != 0 && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (!(tab[x] = (char *)malloc(sizeof(char) * (len + 1))))
				return (0);
			len = 0;
			x++;
		}
		i++;
	}
	return (tab);
}

static char		**ft_fill_tab(char **tab, char const *s, char c)
{
	int	y;
	int x;
	int i;

	y = 0;
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[x][y] = s[i];
			y++;
		}
		if (y != 0 && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	tab[x] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_count;

	if (!s || !c)
		return (0);
	word_count = ft_word_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (0);
	tab = ft_malloc_tab(tab, s, c);
	tab = ft_fill_tab(tab, s, c);
	return (tab);
}
