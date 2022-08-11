/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreduc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:15:15 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:09:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <stdlib.h>

char	*ft_strreduc(char *s, char *set)
{
	size_t	size;
	int		i;
	int		j;
	char	*str;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (!ft_isinset(s[i], set))
			size ++;
		i++;
	}
	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_isinset(s[i], set))
			str[j++] = s[i];
		i++;
	}
	return (str);
}
