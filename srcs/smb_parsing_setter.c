/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_parsing_setter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:27:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/07 23:49:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_struct.h"
#include "smb_settings.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int	check_tag_size(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i + 1] != ':')
		i++;
	return (i);
}

int	check_number(char *nptr)
{
	int	result;
	int	i;
	
	i = 0;
	result = 0;
	while (nptr[i] && nptr[i] != ',')
	{
		if (!ft_isdigit(nptr[i]))
			return (1);
		if (result > result * 10 + (nptr[i] - 48))
			return (1);
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (i == 0)
		return (1);
	return (0);
}

int	parse_line(char *line, char *tag, int *x, int *y)
{
	int	i;
	int	error;

	i = -1;
	if (ft_strlen(line) < 6)
		return (1);
	error = check_tag_size(line);
	if (error > 5)
		return (ft_putstr_fd("Tag too long\n", 2), 1);
	while (line[++i] && line[i] != ':')
		tag[i] = line[i];
	tag[i] = 0;
	i++;
	error = check_number(&line[i]);
	if (error)
		return (ft_putstr_fd("Bad x value\n", 2), 1);
	*x = ft_atoi(&line[i]);
	error = check_number(&line[i]);
	if (error)
		return (ft_putstr_fd("Bad y value\n", 2), 1);
	while (line[i] && line[i] != ',')
		i++;
	i++;
	*y = ft_atoi(&line[i]);
	return (0);
}

void	obj_add_back(t_object **obj, t_object *new)
{
	t_object	*obj_temp;

	if (!obj)
		return ;
	obj_temp = *obj;
	if (!obj_temp)
	{
		*obj = new;
		return ;
	}
	while (obj_temp->next)
		obj_temp = obj_temp->next;
	obj_temp->next = new;
}

t_object	*obj_new(char *tag, float x, float y)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0);
	*obj = (t_object){.tag=tag, .x = x, .y = y};
	return (obj);
}

t_object	*get_object(char *line)
{
	t_object	*object;
	char		tag[6];
	int			x;
	int			y;

	line = ft_strreduc(line, " \t\n\r\v\f");
	if (!line)
		return (0);
	object = ft_calloc(sizeof(t_object), 1);
	if (!object)
		return(free(line), (void *)0);
	if (parse_line(line, tag, &x, &y))
		return(free(line), (void *)0);
	free(line);
	if (!ft_strncmp(tag, "START", 6))
		object = obj_new("START", x, y); //free
	else if (!ft_strncmp(tag, "END", 4))
		object = obj_new("END", x, y); //free
	return(object);
}

t_object	*get_all_object(int fd)
{
	char		*line;
	t_object	*all_objects;
	t_object	*new;

	all_objects = 0;
	line = get_next_line(fd);
	while (line)
	{
		new = get_object(line);
		obj_add_back(&all_objects, new);
		free(line);
		line = get_next_line(fd);
	}
	printf("-%s- -%f- -%f-\n", all_objects->tag, all_objects->x, all_objects->y);
	printf("-%s- -%f- -%f-%d-\n", all_objects->next->tag, all_objects->next->x, all_objects->next->y, all_objects->next->height);
	return (all_objects);
}

/*
* Set map struct and return an error code on error
*/
int	set_map(t_map *map, char *filename)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (8);
	map->map_data = ft_calloc(sizeof(char *), MAP_HEIGHT_TILES + 1);
	if (!map->map_data)
		return (close(fd), 9);
	map->height = MAP_HEIGHT_TILES * TILES_SIZE;
	i = 0;
	while (i < MAP_HEIGHT_TILES)
	{
		map->map_data[i] = get_next_line(fd);
		if (!map->map_data[i])
			return (ft_free_tab(map->map_data), close(fd), 9);
		i++;
	}
	map->width = ft_strlen(map->map_data[0]) * TILES_SIZE;
	map->all_object = get_all_object(fd);
	if (!map->all_object)
		return (ft_free_tab(map->map_data), close (fd), 9);
	close(fd);
	return (0);
}
