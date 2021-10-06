/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:56:30 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:09:33 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t						i;
	unsigned char				*ptr;
	unsigned const char			*ptr2;

	i = 0;
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
			return (dest + i + 1);
		++i;
	}
	return (NULL);
}
