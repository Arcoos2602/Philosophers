/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:22:19 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/15 13:44:51 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *litt, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (litt[0] == '\0')
		return ((char *)big);
	while (i < len && i + 1 <= len && big[i] != '\0')
	{
		j = 0;
		while (litt[j] == big[i + j] && i + j < len)
		{
			if (litt[j + 1] == '\0')
			{
				return ((char *)(big + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}
