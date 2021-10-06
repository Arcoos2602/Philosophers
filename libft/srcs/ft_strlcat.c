/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:31:29 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/16 09:47:23 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (n <= destlen)
		return (srclen + n);
	while ((dest[i] != '\0' && i < n - 1))
		++i;
	while (*src && i < n - 1)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
