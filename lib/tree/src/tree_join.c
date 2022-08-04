/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:59:54 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:23 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list.h"
#include "tree.h"

t_tree	*tree_join(t_list *childs, void *node)
{
	t_tree	*tree;

	tree = tree_new_leaf(node);
	if (!tree)
		return (NULL);
	tree->childs = childs;
	return (tree);
}
