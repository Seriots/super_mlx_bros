/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_depth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:15:18 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:22 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "tree.h"

int	tree_depth(t_tree *tree)
{
	int		depth;
	t_list	*child;
	int		child_depth;

	if (!tree)
		return (-1);
	depth = 0;
	child = tree->childs;
	while (child)
	{
		child_depth = tree_depth(child->content);
		if (child_depth + 1 > depth)
			depth = child_depth + 1;
		child = child->next;
	}
	return (depth);
}
