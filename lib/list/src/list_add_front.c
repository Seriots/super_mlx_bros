/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:53:18 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:15:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_add_front(t_list **lst, t_list *new)
{
	t_list	*last_new;

	if (!lst || !new)
		return ;
	last_new = list_last(new);
	last_new->next = *lst;
	*lst = new;
}
