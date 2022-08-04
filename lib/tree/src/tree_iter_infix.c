/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iter_infix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:57:57 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/08 22:05:05 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_iter_infix(t_tree *tree, void (*f_node)(void *),
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
		tree_iter_infix(child->content, f_node, f_leaf);
		child = child->next;
		if (*f_node && child)
			(*f_node)(tree->content);
	}
}
