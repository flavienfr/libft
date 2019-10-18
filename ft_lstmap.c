/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:51:13 by froussel          #+#    #+#             */
/*   Updated: 2019/10/18 14:03:46 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clean_lst(t_list *lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*next;

	cur = lst;
	while (cur)
	{
		next = cur->next;
		ft_lstdelone(cur, del);
		cur = next;
	}
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;
	t_list	*beg;

	if (!lst || !f || !del)
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (new);
	beg = new;
	lst = lst->next;
	while (lst)
	{
		next = lst->next;
		if (!(new->next = ft_lstnew((*f)(lst->content))))
			return (clean_lst(beg, del));
		lst = next;
	}
	return (beg);
}
