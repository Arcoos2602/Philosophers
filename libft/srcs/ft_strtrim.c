/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:12:48 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:28:31 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_begin(char const *s1, char const *set)
{
	int		i;
	int		begin;

	i = 0;
	begin = 0;
	while (set[i] && s1[begin] != '\0')
	{
		i = 0;
		while (set[i] != s1[begin] && set[i] != '\0')
			i++;
		if (set[i] == s1[begin])
			begin++;
	}
	return (begin);
}

static int	ft_end(char const *s1, char const *set)
{
	int		len;
	int		i;

	len = 0;
	len = ft_strlen(s1) - 1;
	i = 0;
	while (set[i] && len >= 0)
	{
		i = 0;
		while (set[i] != s1[len] && set[i] != '\0')
			i++;
		if (set[i] == s1[len])
			len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		b;
	int		e;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	e = ft_end(s1, set);
	b = ft_begin(s1, set);
	if (e - b < 0)
	{
		s = ft_calloc(1, 1);
		return (s);
	}
	s = malloc(e - b + 2);
	if (s == NULL)
		return (NULL);
	while (e - b >= i)
	{
		s[i] = s1[i + b];
		i++;
	}
	s[i] = '\0';
	return (s);
}
