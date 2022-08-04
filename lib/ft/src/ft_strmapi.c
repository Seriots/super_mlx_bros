/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:07:51 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 17:46:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_map;
	unsigned int	i;

	if (!s || !(*f))
		return (0);
	str_map = malloc(ft_strlen(s) + 1);
	if (!str_map)
		return (0);
	i = 0;
	while (s[i])
	{
		str_map[i] = f(i, s[i]);
		i++;
	}
	str_map[i] = '\0';
	return (str_map);
}
