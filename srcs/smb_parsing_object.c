/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_parsing_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:20:43 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 15:00:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "dict.h"

#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

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

t_dict	*get_object(char *line)
{
	t_dict		*dict;
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
	dict = 0;
	object = obj_new(tag, x, y);
	if (object)
		dict = get_dict_new(tag, object);
	if (!dict && object)
		return (free(object), (void *)0);
	return(dict);
}

t_dict	*get_all_object(int fd)
{
	char		*line;
	t_dict	*all_objects;
	t_dict	*new;

	all_objects = 0;
	line = get_next_line(fd);
	while (line)
	{
		new = get_object(line);
		free(line);
		if (new)
			dict_add_back(&all_objects, new);
		line = get_next_line(fd);
	}
	return (all_objects);
}
