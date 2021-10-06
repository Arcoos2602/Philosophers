/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:09:38 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/12 19:26:12 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while (i-- >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
