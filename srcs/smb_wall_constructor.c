/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_wall_constructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:55:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 21:05:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESULT_INCREMENT 1
/*
* Take a map of 0 and 1, (0 empty space, 1 wall) and output a map where everyone 1 are replace by 
* a different character corresponding to 1 of 16 tiles to put in the map. you can play with this plage
* of value with the macro RESULT_INCREMENT. Default: value are between 'A' and 'O'.
* This can work on a Non-rectangular map.
*/
void	convert_outdoor_map(char **map, int x, int y, int max_y)
{
	char	result;

	result = 64;
	if ((y != 0 && map[y - 1][x] != '0' ))
		result = result | 2;
	if ((map[y][x + 1] != 0 && map[y][x + 1] != '0'))
		result = result | 4;
	if ((y < max_y && map[y + 1][x] != '0'))
		result = result | 8;
	if ((x != 0 && map[y][x - 1] != '0'))
		result = result | 1;
	map[y][x] = result + RESULT_INCREMENT;
}

void	convert_indoor_map(char **map, int x, int y, int max_y)
{
	char	result;

	result = 64;
	if ((y != 0 && map[y - 1][x] != '0' )
		|| (y == 0 && map[y][x + 1] != 0 && x != 0))
		result = result | 2;
	if ((map[y][x + 1] != 0 && map[y][x + 1] != '0')
		|| (map[y][x + 1] == 0 && y != 0 && y < max_y))
		result = result | 4;
	if ((y < max_y && map[y + 1][x] != '0')
		|| (y >= max_y && map[y][x + 1] != 0 && x != 0))
		result = result | 8;
	if ((x != 0 && map[y][x - 1] != '0')
		|| (x == 0 && y != 0 && y < max_y))
		result = result | 1;
	map[y][x] = result + RESULT_INCREMENT;
}

void	convert_plateformer_map(char **map, int x, int y, int max_y)
{
	char	result;

	result = 64;
	if ((y != 0 && map[y - 1][x] != '0' )
		|| (y == 0))
		result = result | 2;
	if ((map[y][x + 1] != 0 && map[y][x + 1] != '0')
		|| (map[y][x + 1] == 0))
		result = result | 4;
	if ((y < max_y && map[y + 1][x] != '0')
		|| (y >= max_y))
		result = result | 8;
	if ((x != 0 && map[y][x - 1] != '0')
		|| (x == 0))
		result = result | 1;
	map[y][x] = result + RESULT_INCREMENT;
}

/*
* You can pass different convert_function to apply a different placement of your tiles onthe map
* outdoor map: border tiles are straight line.
* indoor map: border tiles are considering wall everywhere outside the map.
*/
void	wall_constructor(char **map, int max_y,
					void (*convert_function)(char **, int, int, int))
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				convert_function(map, x, y, max_y - 1);
			x++;
		}
		y++;
	}
}
