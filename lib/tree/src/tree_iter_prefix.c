/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iter_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:53:31 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/08 22:05:18 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_iter_prefix(t_tree *tree, void (*f_node)(void *),
	void (*f_leaf)(void *))
{
	t_list	*child;

	if (!tree)
		return ;
	if (!tree->childs)
	{
		if (*f_leaf)
			(*f_leaf)(tree->content);
		return ;
	}
	if (*f_node)
		(*f_node)(tree->content);
	child = tree->childs;
	while (child)
	{
		tree_iter_prefix(child->content, f_node, f_leaf);
		child = child->next;
	}
}
