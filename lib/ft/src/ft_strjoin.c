/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:42:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 17:46:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_join = malloc(len_s1 + len_s2 + 1);
	if (!s_join)
		return (0);
	ft_strlcpy(s_join, s1, len_s1 + 1);
	ft_strlcpy(s_join + len_s1, s2, len_s2 + 1);
	return (s_join);
}
