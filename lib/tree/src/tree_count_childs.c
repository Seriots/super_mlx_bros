/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_count_childs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:42:10 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/01 08:39:14 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "tree.h"

int	tree_count_childs(t_tree *tree)
{
	if (!tree)
		return (0);
	return (list_size(tree->childs));
}
