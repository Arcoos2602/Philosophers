/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:17:42 by tcordonn          #+#    #+#             */
/*   Updated: 2020/07/25 15:34:45 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst == NULL)
		return ;
	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		new->next = 0;
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
		new->next = 0;
	}
}
