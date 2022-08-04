/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_count_leaves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:39:41 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:22 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "tree.h"

int	tree_count_leaves(t_tree *tree)
{
	int		count;
	t_list	*child;

	if (!tree)
		return (0);
	if (!tree->childs)
		return (1);
	count = 0;
	child = tree->childs;
	while (child)
	{
		count += tree_count_leaves(child->content);
		child = child->next;
	}
	return (count);
}
