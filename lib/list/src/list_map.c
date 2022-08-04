/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:45:07 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:15:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_revlst(t_list **lst)
{
	t_list	*lst_rev;
	t_list	*lst_temp;

	if (!lst)
		return ;
	lst_rev = 0;
	while (*lst)
	{
		lst_temp = *lst;
		*lst = lst_temp->next;
		lst_temp->next = 0;
		list_add_front(&lst_rev, lst_temp);
	}
	*lst = lst_rev;
}

t_list	*list_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_mapped;
	t_list	*elem;

	if (!(*f) || !(*del))
		return (0);
	lst_mapped = 0;
	while (lst)
	{
		elem = list_new((*f)(lst->content));
		if (!elem)
		{
			list_clear(&lst_mapped, (*del));
			return (0);
		}
		list_add_front(&lst_mapped, elem);
		lst = lst->next;
	}
	ft_revlst(&lst_mapped);
	return (lst_mapped);
}
