/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:54:16 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 17:46:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*addr_dest;
	unsigned char	*addr_src;
	size_t			i;

	addr_dest = (unsigned char *) dest;
	addr_src = (unsigned char *) src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	i = n - 1;
	while (i < n)
	{
		addr_dest[i] = addr_src[i];
		i--;
	}
	return (dest);
}
