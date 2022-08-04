/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iter_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:45:35 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:22 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "tree.h"

int	tree_iter_if(t_tree *tree, int (*test_node)(void *, int),
	int (*f_leaf)(void *))
{
	int		return_value;
	t_list	*child;

	if (!tree || !*test_node || !*f_leaf)
		return (-1);
	if (!tree->childs)
		return ((*f_leaf)(tree->content));
	child = tree->childs;
	return_value = tree_iter_if(child->content, test_node, f_leaf);
	child = child->next;
	while (child && (*test_node)(child->content, return_value))
	{
		return_value = tree_iter_if(child->content, test_node, f_leaf);
		child = child->next;
	}
	return (return_value);
}
