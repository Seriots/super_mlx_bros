/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:37:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/09 21:07:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dict.h"
#include "../include/libft.h"
#include <stdlib.h>

t_dict	*clear_copy(t_dict *copy, void *key, void *value)
{
	dict_clear(copy, free, free);
	free(key);
	free(value);
	return (0);
}

static t_dict	*init_copy(t_dict *dict, void **key, void **value, t_dict *copy)
{
	if (dict->key)
	{
		*key = ft_calloc(sizeof(char), ft_strlen(dict->key) + 1);
		if (!*key)
			return (clear_copy(copy, *key, *value));
	}
	if (dict->value)
	{
		*value = ft_calloc(sizeof(char), ft_strlen(dict->value) + 1);
		if (!*value)
			return (clear_copy(copy, *key, *value));
	}
	if (*key)
		ft_strlcpy(*key, dict->key, ft_strlen(dict->key) + 1);
	if (*value)
		ft_strlcpy(*value, dict->value, ft_strlen(dict->value) + 1);
	return (dict);
}

t_dict	*dict_copy(t_dict *dict)
{
	t_dict	*copy;	
	t_dict	*new;
	void	*key;
	void	*value;

	if (!dict)
		return (0);
	copy = 0;
	key = 0;
	value = 0;
	while (dict)
	{
		if (!init_copy(dict, &key, &value, copy))
			return (0);
		new = dict_new(key, value);
		if (!new)
			return (clear_copy(copy, key, value));
		dict_add_back(&copy, new, free, free);
		dict = dict->next;
	}
	return (copy);
}
