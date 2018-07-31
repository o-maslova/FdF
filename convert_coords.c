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
	len_x = (int)(HALF_X * SCALE);
	len_y = (int)(HALF_Y * SCALE);
	while (i < win->rows)
	{
		j = 0;
		while (j < win->columns)
		{
			win->mod_arr[i][j].x = (int)arr[i][j].x + MOVE_RIGHT - len_x;
			win->mod_arr[i][j].x += (WIDTH / 2);
			win->mod_arr[i][j].y = (int)arr[i][j].y + MOVE_UP - len_y;
			win->mod_arr[i][j].y += (HEIGTH / 2);
			win->mod_arr[i][j].color = arr[i][j].color;
			if (win->arr[i][j].color == 0xFFFFFF && win->flag == 0)
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
	if (HIGH > 20)
		HIGH = 20;
	else if (HIGH < -20)
		HIGH = -20;
	t_z = dot.z * HIGH;
	map->y = (int)((t_y - Y) * cos(R_x) + (t_z - Z) * -sin(R_x)) + Y;
	map->z = (int)((t_y - Y) * sin(R_x) + (t_z - Z) * cos(R_x)) + Z;
	t_z = (int)map->z;
	map->x = (int)((t_x - X) * cos(R_y) + (t_z - Z) * sin(R_y)) + X;
	map->z = (int)((t_x - X) * -sin(R_y) + (t_z - Z) * cos(R_y)) + Z;
	t_y = (int)map->y;
	t_x = (int)map->x;
	map->x = (int)((t_x - X) * cos(R_z) + (t_y - Y) * -sin(R_z)) + X;
	map->y = (int)((t_y - Y) * cos(R_z) + (t_x - X) * sin(R_z)) + Y;
	map->z = 0;
	if (win->flag == 0)
		map->color = dot.color;
}

t_coords	**convert(t_window *win)
{
	int i;
	int j;

	i = -1;
	win->cen->x = win->arr[HALF_X][HALF_Y].x * SCALE;
	win->cen->y = win->arr[HALF_X][HALF_Y].y * SCALE;
	win->cen->z = win->arr[HALF_X][HALF_Y].z * HIGH;
	while (++i < win->rows)
	{
		j = 0;
		while (j < win->columns)
		{
			xyz_to_xy(win, win->arr[i][j], &win->mod_arr[i][j]);
			j++;
		}
	}
	win->mod_arr = to_center(win, win->mod_arr);
	return (win->mod_arr);
}
