/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iter_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:57:16 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/08 22:05:28 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_iter_suffix(t_tree *tree, void (*f_node)(void *),
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
	child = tree->childs;
	while (child)
	{
		tree_iter_suffix(child->content, f_node, f_leaf);
		child = child->next;
	}
	if (*f_node)
		(*f_node)(tree->content);
}
