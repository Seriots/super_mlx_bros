/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:22:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/07/12 18:44:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dict.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include <stdio.h>

static char	*dict_to_str(t_dict *dict)
{
	size_t	size;
	char	*result;

	if (!dict)
		return (0);
	size = ft_strlen(dict->key) + ft_strlen(dict->value) + 1;
	result = ft_calloc(sizeof(char), size + 1);
	if (!result)
		return (0);
	ft_strlcat(result, dict->key, size + 1);
	ft_strlcat(result, "=", size + 1);
	ft_strlcat(result, dict->value, size + 1);
	return (result);
}

char	**dict_to_array(t_dict *dict)
{
	char	**result;
	size_t	i;

	if (!dict)
		return (0);
	result = ft_calloc(sizeof(char *), dict_size(dict) + 1);
	if (!result)
		return (0);
	i = 0;
	while (dict)
	{
		result[i] = dict_to_str(dict);
		if (!result[i])
			return (ft_free_tab(result), (void *)0);
		dict = dict->next;
		i++;
	}
	return (result);
}
