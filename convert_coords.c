/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:58:19 by omaslova          #+#    #+#             */
/*   Updated: 2018/07/09 15:58:35 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		memory_free(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char		*cancat(char *line, char **str)
{
	int		i;
	int		j;
	char	*res_1;
	char	*res_2;

	j = -1;
	if (*str == NULL)
	{
		*str = ft_strdup(line);
		return (*str);
	}
	res_1 = ft_strdup(*str);
	res_2 = ft_memalloc(ft_strlen(res_1) + ft_strlen(line) + 2);
	while (res_1[++j] != '\0')
		res_2[j] = res_1[j];
	res_2[j++] = '\n';
	i = 0;
	while (line[i] != '\0')
		res_2[j++] = line[i++];
	res_2[j] = '\0';
	free(res_1);
	free(*str);
	return (res_2);
}

t_coords	**to_center(t_window *win, t_coords **arr)
{
	int i;
	int j;
	int len_x;
	int len_y;

	i = 0;
	len_x = (win->columns * SCALE) / 2;
	len_y = (win->rows * SCALE) / 2;
	while (i < win->rows)
	{
		j = 0;
		while (j < win->columns)
		{
			win->mod_arr[i][j].x = arr[i][j].x + MOVE_RIGHT - len_x;
			win->mod_arr[i][j].x += (WIDTH / 2);
			win->mod_arr[i][j].y = arr[i][j].y + MOVE_UP - len_y;
			win->mod_arr[i][j].y += (HEIGTH / 2);
			win->mod_arr[i][j].color = arr[i][j].color;
			if (win->arr[i][j].color == 0xFFFFFF)
				win->mod_arr[i][j].color = COLOR;
			j++;
		}
		i++;
	}
	return (win->mod_arr);
}

void		xyz_to_xy(t_window *win, t_coords dot, t_coords *map)
{
	double t_x;
	double t_y;
	double t_z;

	t_x = dot.x * SCALE;
	t_y = dot.y * SCALE;
	if (HIGH > 30)
		HIGH = 30;
	else if (HIGH < -30)
		HIGH = -30;
	t_z = dot.z * HIGH;
	map->y = (int)(t_y * cos(R_x) + t_z * -sin(R_x));
	map->z = (int)(t_y * sin(R_x) + t_z * cos(R_x));
	t_z = (int)map->z;
	map->x = (int)(t_x * cos(R_y) + t_z * sin(R_y));
	map->z = (int)(t_x * -sin(R_y) + t_z * cos(R_y));
	t_y = (int)map->y;
	t_x = (int)map->x;
	map->x = (int)(t_x * cos(R_z) + t_y * -sin(R_z));
	map->y = (int)(t_y * cos(R_z) + t_x * sin(R_z));
	map->z = 0;
	map->color = dot.color;
}

t_coords	**convert(t_window *win)
{
	int i;
	int j;

	i = 0;
	while (i < win->rows)
	{
		j = 0;
		while (j < win->columns)
		{
			xyz_to_xy(win, win->arr[i][j], &win->mod_arr[i][j]);
			j++;
		}
		i++;
	}
	return (win->mod_arr);
}
