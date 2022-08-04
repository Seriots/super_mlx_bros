/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:33:13 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:15:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_add_back(t_list **lst, t_list *new)
{
	t_list	*lst_temp;

	if (!lst)
		return ;
	lst_temp = *lst;
	if (!lst_temp)
	{
		*lst = new;
		return ;
	}
	while (lst_temp->next)
		lst_temp = lst_temp->next;
	lst_temp->next = new;
}
