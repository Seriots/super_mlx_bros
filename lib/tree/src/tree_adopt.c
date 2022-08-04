/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_adopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:29:18 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/04 23:34:05 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/tree.h"

int	tree_adopt(t_tree *parent, t_tree *child)
{
	t_list	*child_l;

	child_l = list_new(child);
	if (!child_l)
		return (-1);
	list_add_back(&parent->childs, child_l);
	return (0);
}
