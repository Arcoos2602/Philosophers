/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:17:58 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 11:04:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!f)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
