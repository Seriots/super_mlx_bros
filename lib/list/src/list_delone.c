/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:35:55 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:15:35 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void	list_delone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (*del)
		(*del)(lst->content);
	free(lst);
}
