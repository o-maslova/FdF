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

t_coords	**memmaloc(t_window *win)
{
	int i;

	i = -1;
	win->mod_arr = (t_coords **)malloc(sizeof(t_coords *) * win->rows);
	while (++i < win->rows)
		win->mod_arr[i] = (t_coords *)malloc(sizeof(t_coords) * win->columns);
	return (win->mod_arr);
}

t_window	*initialization(t_window *win)
{
	static int tmp;

	win->cen = (t_coords *)malloc(sizeof(t_coords));
	win->max = win->arr[0][0].z;
	win->color = 0xFFFFFF;
	win->corn_x = 1;
	win->corn_y = 0.5;
	win->corn_z = 0;
	if (tmp == 0 || win->heigth == 1000)
	{
		win->high = 5;
		win->scale = 10;
		win->heigth = 1000;
		win->width = 1000;
	}
	win->move_right = 0;
	win->move_up = 0;
	win->flag = 0;
	tmp++;
	return (win);
}

int			deal_key(int key, t_window *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	if (key == 53)
		exit(0);
	if (key == 69)
		SCALE += 1;
	if (key == 78)
		SCALE -= 1;
	if (key == 49)
	{
		free(win->cen);
		win = initialization(win);
	}
	if (key == 6)
		win->mod_arr = gradient(&win);
	turn(key, win);
	move(key, win);
	color(key, win);
	win->mod_arr = convert(win);
	draw(win, win->mod_arr);
	return (0);
}

void		draw(t_window *win, t_coords **arr)
{
	int i;
	int j;

	i = 0;
	display_first(win);
	display_second(win);
	while (i < win->rows)
	{
		j = 0;
		while (j < win->columns)
		{
			if (i + 1 < win->rows)
				algoritm(win, arr[i][j], arr[i + 1][j]);
			if (j + 1 < win->columns)
				algoritm(win, arr[i][j], arr[i][j + 1]);
			j++;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_window	*win;

	if (argc > 2 || argc == 1)
		error_handling(2);
	win = (t_window *)malloc(sizeof(t_window));
	win->arr = parsing(argv[1], &win);
	win->mod_arr = memmaloc(win);
	win = initialization(win);
	win->mlx_ptr = mlx_init();
	win->mod_arr = convert(win);
	if (win->mod_arr[0][win->columns - 1].y < 0 ||
	win->mod_arr[win->rows - 1][win->columns - 1].x >= win->width)
	{
		win->scale -= 7;
		win->high -= 4;
		win->heigth = 1200;
		win->width = 1500;
		win->mod_arr = convert(win);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGTH, "mlx 42");
	draw(win, win->mod_arr);
	mlx_hook(win->win_ptr, 2, 0, deal_key, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
