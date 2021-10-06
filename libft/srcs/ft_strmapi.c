/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:54:48 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/21 19:26:42 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;

	i = -1;
	if (!s)
		return (0);
	string = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (s[++i])
		string[i] = f(i, s[i]);
	string[i] = '\0';
	return (string);
}
