/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:13:54 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:30:54 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_free(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int	ft_cpt(char const *str, char charset)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		while (str[i] == charset && str[i] != '\0')
			i++;
		if (str[i] != charset && str[i] != '\0')
		{
			a++;
			while (str[i] != charset && str[i] != '\0')
				i++;
		}
	}
	i--;
	return (a);
}

static int	ft_init(char **tab, char const *str, char c)
{
	int	b;
	int	a;
	int	i;

	i = 0;
	a = 0;
	b = 0;
	while (b < ft_cpt(str, c))
	{
		a = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != '\0' && str[i++] != c)
			a++;
		tab[b] = (char *)malloc(sizeof(char) * (a + 1));
		if (tab[b] == NULL)
			return (ft_free(tab, i));
		b++;
	}
	tab[b] = 0;
	return (1);
}

void	norm_v3_is_shit(const char *str, char c, int *i)
{
	while (str[*i] == c && str[*i] != '\0')
		++*i;
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		b;

	a = 0;
	i = 0;
	b = 0;
	tab = 0;
	tab = malloc(sizeof(char *) * (ft_cpt(str, c) + 1));
	if (!(str) || tab == NULL)
		return (NULL);
	if (!ft_init(tab, str, c))
		return (0);
	norm_v3_is_shit(str, c, &i);
	while (str[i] != '\0')
	{
		b = 0;
		while (str[i] != c && str[i] != '\0')
			tab[a][b++] = str[i++];
		while (str[i] == c && str[i] != '\0')
			i++;
		tab[a++][b] = '\0';
	}
	return (tab);
}
