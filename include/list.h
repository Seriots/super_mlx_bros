/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 01:15:51 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/10 19:12:32 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	list_add_back(t_list **lst, t_list *new);
void	list_add_front(t_list **lst, t_list *new);
int		list_append(t_list **lst, void *content);
int		list_append_back(t_list **lst, void *content);
void	list_clear(t_list **lst, void (*del)(void *));
void	list_delone(t_list *lst, void (*del)(void *));
void	list_iter(t_list *lst, void (*f)(void *));
t_list	*list_last(t_list *lst);
t_list	*list_map(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*list_new(void *content);
void	list_rev(t_list **l);
int		list_size(t_list *lst);

#endif
