/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:25:09 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/01 04:03:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "list.h"

typedef struct s_tree
{
	void	*content;
	t_list	*childs;
}	t_tree;

int		tree_adopt(t_tree *parent, t_tree *child);
void	tree_clear(t_tree *tree, void (*free_node)(void *));
int		tree_count_childs(t_tree *tree);
int		tree_count_leaves(t_tree *tree);
int		tree_depth(t_tree *tree);
int		tree_iter_if(t_tree *tree, int (*test_node)(void *, int),
			int (*f_leaf)(void *));
void	tree_iter_infix(t_tree *tree, void (*f_node)(void *),
			void (*f_leaf)(void *));
void	tree_iter_prefix(t_tree *tree, void (*f_node)(void *),
			void (*f_leaf)(void *));
void	tree_iter_suffix(t_tree *tree, void (*f_node)(void *),
			void (*f_leaf)(void *));
t_tree	*tree_join(t_list *childs, void *node);
t_tree	*tree_join_two(t_tree *tree_left, t_tree *tree_right, void *node);
t_tree	*tree_new_leaf(void *content);
int		tree_size(t_tree *tree);
#endif
