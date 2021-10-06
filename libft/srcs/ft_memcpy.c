/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:07:28 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:10:51 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr;
	const char	*ptr2;

	if (dest == 0 && src == 0)
		return (0);
	ptr = dest;
	ptr2 = src;
	while (n--)
		*ptr++ = *ptr2++;
	return (dest);
}
