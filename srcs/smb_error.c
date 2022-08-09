/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:12:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 23:25:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_settings.h"

static void	smb_print_parsing_error(int code)
{
	if (code == 4)
		ft_putstr_fd("Bad number of arguments\n", 2);
	else if (code == 5)
		ft_putstr_fd("No\n", 2);
	else if (code == 6)
		ft_putstr_fd("Invalid map structure\n", 2);
	else if (code == 7)
		ft_putstr_fd("Invalid map extensions\n", 2);
	ft_putstr_fd("Usage: ./", 2);
	ft_putstr_fd(EXE_NAME, 2);
	ft_putstr_fd(" <file.map> \n", 2);
}

void	smb_print_error(int code)
{
	if (code == 1)
		ft_putstr_fd("Mlx initialisation fail\n", 2);
	else if (code == 2)
		ft_putstr_fd("Window creation fail\n", 2);
	else if (code == 3)
		ft_putstr_fd("Image initialisation fail\n", 2);
	else if (code >= 4 && code <= 7)
		smb_print_parsing_error(code);
	else if (code == 8)
		ft_putstr_fd("Open fail\n", 2);
	else if (code == 9)
		ft_putstr_fd("Malloc fail\n", 2);
	else if (code == 11)
		ft_putstr_fd("Need a start position\n", 2);
	else if (code == 12)
		ft_putstr_fd("Need at least an end position\n", 2);
	else if (code == 10)
		ft_putstr_fd("No objects\n", 2);
}
