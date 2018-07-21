#include "fdf.h"

t_coords	**to_center(t_window *win, t_coords **arr)
{
	int i;
	int j;
	int len_x;
	int len_y;
	t_coords **tmp;

	i = 0;
	len_x = win->columns * (arr[0][1].x -arr[0][0].x);
	len_y = win->rows * (arr[1][0].y - arr[0][0].y);
	tmp = (t_coords **)malloc(sizeof(t_coords *) * win->rows);
	while (i < win->rows)
	{
		j = 0;
		tmp[i] = (t_coords *)malloc(sizeof(t_coords) * win->columns);
		while (j < win->columns)
		{
			tmp[i][j].x = (arr[i][j].x + (WIDTH / 2) - (len_x / 2)) + MOVE_RIGHT;
			tmp[i][j].y = (arr[i][j].y + (HEIGTH / 2) - (len_y / 2)) + MOVE_UP;
			j++;
		}
		i++;
	}
	return (tmp);
}

void	xyz_to_xy(t_window *win, t_coords dot, t_coords *map)
{
	double t_x;
	double t_y;
	double t_z;
	
	t_x = dot.x * SCALE;
	t_y = dot.y * SCALE;
	t_z = dot.z * HIGH;
	map->y = (int)(t_y * cos(R_x) + t_z * -sin(R_x));
	map->z = (int)(t_y * sin(R_x) + t_z * cos(R_x));
	t_z = map->z;
	map->x = (int)(t_x * cos(R_y) + t_z * sin(R_y));
	map->z = (int)(t_x * -sin(R_y) + t_z * cos(R_y));
	t_y = map->y;
	t_x = map->x;
	map->x = (int)(t_x * cos(R_z) + t_y * -sin(R_z));
	map->y = (int)(t_y * cos(R_z) + t_x * sin(R_z));
}

t_coords	**convert(t_window *win)
{
	int i;
	int j;

	i = 0;
	win->mod_arr = (t_coords **)malloc(sizeof(t_coords *) * win->rows);
	while (i < win->rows)
	{
		j = 0;
		win->mod_arr[i] = (t_coords *)malloc(sizeof(t_coords) * win->columns);
		while (j < win->columns)
		{
			xyz_to_xy(win, win->arr[i][j], &win->mod_arr[i][j]);
			j++;
		}
		i++;
	}
	return (win->mod_arr);
}