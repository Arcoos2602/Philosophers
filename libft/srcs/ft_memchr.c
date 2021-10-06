/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:30:02 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:16:58 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == c)
			return ((unsigned char *)s + i);
		++i;
	}
	return (NULL);
}
