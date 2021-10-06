/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:27:22 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 10:49:47 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t element_count, size_t element_size)
{
	void	*ptr;

	if (element_count == 0 || element_size == 0)
	{
		element_count = 1;
		element_size = 1;
	}
	ptr = malloc(element_count * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, element_count * element_size);
	return (ptr);
}
