/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_join_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:02:32 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/01 08:40:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"
#include "tree.h"

t_tree	*tree_join_two(t_tree *tree_left, t_tree *tree_right, void *node)
{
	t_list	*childs;
	t_list	*child_left;
	t_list	*child_right;

	child_left = list_new(tree_left);
	if (!child_left)
		return (NULL);
	child_right = list_new(tree_right);
	if (!child_right)
	{
		list_clear(&child_left, NULL);
		return (NULL);
	}
	childs = NULL;
	list_add_front(&childs, child_right);
	list_add_front(&childs, child_left);
	return (tree_join(childs, node));
}
