/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:53:30 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/04 22:50:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft.h"
#include "smb_struct.h"

#include <unistd.h>

int	main(int argc, char **argv)
{
	t_game	game;

	mlx = mlx_init();
	
	mlx_destroy_display(mlx);
}