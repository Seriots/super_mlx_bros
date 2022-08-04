/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:12:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 01:25:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	smb_print_error(int code)
{
	if (code == 1)
		ft_putstr_fd("Mlx initialisation fail\n", 2);
	else if (code == 2)
		ft_putstr_fd("Window creation fail\n", 2);
	else if (code == 3)
		ft_putstr_fd("Image initialisation fail\n", 2);
}
