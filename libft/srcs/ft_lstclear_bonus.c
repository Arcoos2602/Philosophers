/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:17:18 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:11:35 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p1;
	t_list	*tmp;

	p1 = *lst;
	tmp = p1;
	while (lst && p1 && del)
	{
		p1 = p1->next;
		ft_lstdelone(tmp, del);
		tmp = p1;
	}
	*lst = 0;
}
