/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:03:31 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:31:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_size(char const *s, unsigned int start, size_t len)
{
	int		i;

	i = 1;
	while (s[start + i] != '\0' && i < (int)len)
		i++;
	if (s[start + i] == '\0' && i >= (int)len)
		i++;
	return (i + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	while (i++ != (int)start)
	{
		if (s[i] == '\0')
		{
			result = ft_calloc(1, 1);
			return (result);
		}
	}
	result = malloc(sizeof(char) * ft_size(s, start, len));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < (int)len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
