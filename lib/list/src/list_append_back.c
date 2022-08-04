/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:11:40 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/10 19:11:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_append_back(t_list **lst, void *content)
{
	t_list	*elem;

	elem = list_new(content);
	if (!elem)
		return (-1);
	list_add_back(lst, elem);
	return (0);
}
