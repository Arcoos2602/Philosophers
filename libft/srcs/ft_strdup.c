/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:58:34 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:29:57 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s2;

	i = -1;
	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (s[++i] != 0)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}
