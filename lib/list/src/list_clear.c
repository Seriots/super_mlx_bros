/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:37:21 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:15:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_clear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_temp;

	if (!lst)
		return ;
	while (*lst)
	{
		lst_temp = *lst;
		*lst = lst_temp->next;
		list_delone(lst_temp, *del);
	}
}
