/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:05:11 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:10:25 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	const char		*ptr;
	const char		*ptr2;

	i = 0;
	ptr = (const char *)s1;
	ptr2 = (const char *)s2;
	while (n--)
	{
		if (ptr[i] != ptr2[i])
			return ((unsigned char)ptr[i] - ptr2[i]);
		i++;
	}
	return (0);
}
