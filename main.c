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

int			deal_key(int key, t_window *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	if (key == 53)
		exit (0);
	if (key == 69)
		SCALE += 0.2;
	if (key == 78)
		SCALE -= 0.2;
	if (key == 13)
		R_x += 0.2;
	if (key == 1)
		R_x -= 0.2;
	if (key == 2)
		R_y += 0.2;
	if (key == 0)
		R_y -= 0.2;
	if (key == 12)
		R_z += 0.2;
	if (key == 14)
		R_z -= 0.2;
	if (key == 116)
		HIGH += 1;
	if (key == 121)
		HIGH -= 1;
	if (key == 124)
		MOVE_RIGHT += 10;
	if (key == 123)
		MOVE_RIGHT -= 10;
	if (key == 126)
		MOVE_UP -= 10;
	if (key == 125)
		MOVE_UP += 10;
	win->mod_arr = convert(win);
	draw(win, to_center(win, win->mod_arr));
	return (0);
}

void		draw(t_window *win, t_coords **arr)
{
	int i;
	int j;

	i = 0;
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
	
	argc = 0;
	win = (t_window *)malloc(sizeof(t_window));
	win->arr = parsing(argv[1], &win);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGTH, "mlx 42");
	win->mod_arr = convert(win);
	draw(win, to_center(win, win->mod_arr));
	mlx_hook(win->win_ptr, 2, 0, deal_key, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
