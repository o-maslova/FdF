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
	if (key == 89)
		R_x += 0.2;
	if (key == 83)
		R_x -= 0.2;
	if (key == 87)
		R_y += 0.2;
	if (key == 86)
		R_y -= 0.2;
	if (key == 84)
		R_z += 0.2;
	if (key == 91)
		R_z -= 0.2;
	if (key == 116)
		HIGH += 1;
	if (key == 121)
		HIGH -= 1;
	if (key == 124)
		MOVE_RIGHT += 10;
	if (key == 123)
		MOVE_RIGHT -= 10;
	if (key == 92)
		MOVE_UP -= 10;
	if (key == 85)
		MOVE_UP += 10;
//	win->mod_arr = convert(win);
	draw(win, to_center(win, convert(win)));
	return (0);
}

void		draw(t_window *win, t_coords **arr)
{
	int i;
	int j;

	i = 0;
	display(win);
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
	if ((win->arr = parsing(argv[1], &win)) != NULL)
	{
		win->mlx_ptr = mlx_init();
		win->width = 1000;
		win->heigth = 1000;
		win->mod_arr = to_center(win, convert(win));
	//	printf("dot2.x = %f,  dot2.y = %f", win->mod_arr[win->rows - 1][win->columns - 1].x, win->mod_arr[win->rows - 1][win->columns - 1].y);
		if (win->mod_arr[win->rows - 1][win->columns - 1].x >= win->width || 
		win->mod_arr[win->rows - 1][win->columns - 1].y >= win->heigth)
		{
			win->scale -= 4;
			win->heigth = 1000;
			win->width = 1500;
		//	printf("\n\ndot.x = %f,  dot.y = %f", win->mod_arr[win->rows - 1][win->columns - 1].x, win->mod_arr[win->rows - 1][win->columns - 1].y);
			win->mod_arr = to_center(win, convert(win));
		}
		win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGTH, "mlx 42");
		draw(win, win->mod_arr);
		mlx_hook(win->win_ptr, 2, 0, deal_key, win);
		mlx_loop(win->mlx_ptr);
	}
	return (0);
}
