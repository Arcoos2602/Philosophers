/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:06:58 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 10:58:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	calc(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	boucle(char *str, long *nb, int *i)
{
	++*i;
	while (*nb > 0)
	{
		str[--*i] = 48 + (*nb % 10);
		*nb = *nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = calc(n);
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	boucle(str, &nb, &i);
	return (str);
}
