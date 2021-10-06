/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:38:24 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/24 15:35:14 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*string;

	i = -1;
	j = -1;
	if (s2 == 0 || s1 == 0)
		return (NULL);
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		string[i] = s1[i];
	while (s2[++j] != '\0')
		string[j + i] = s2[j];
	string[i + j] = '\0';
	return (string);
}
