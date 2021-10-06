/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:41 by tcordonn          #+#    #+#             */
/*   Updated: 2019/10/12 18:17:05 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		d;
	int		u;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		d = n / 10;
		u = n % 10;
		ft_putnbr_fd(d, fd);
		ft_putchar_fd(u + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
