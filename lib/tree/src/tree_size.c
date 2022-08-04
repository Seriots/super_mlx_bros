/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:13:36 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:23 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "tree.h"

int	tree_size(t_tree *tree)
{
	int		count;
	t_list	*child;

	if (!tree)
		return (0);
	count = 1;
	child = tree->childs;
	while (child)
	{
		count += tree_size(child->content);
		child = child->next;
	}
	return (count);
}
