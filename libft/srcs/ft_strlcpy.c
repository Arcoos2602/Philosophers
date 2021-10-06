/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:34:58 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/16 13:49:29 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0' && i + 1 < size)
		{
			dst[i] = src[i];
			++i;
		}
		if (i < size)
			dst[i] = '\0';
		while (src[i] != '\0')
			++i;
	}
	return (i);
}
