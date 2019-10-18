/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:51:13 by froussel          #+#    #+#             */
/*   Updated: 2019/10/18 10:38:16 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;
	t_list	*beg;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	beg = new;
	lst = lst->next;
	while (lst)
	{
		next = lst->next;
		if (!(*f)(lst->content))
			(*del)(lst->content);
		new->next = ft_lstnew(lst->content);
		lst = next;
	}
	return (beg);
}
