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

int			deal_key(int key, param *tmp)
{
//	static int k;
	
	mlx_clear_window(tmp->win->mlx_ptr, tmp->win->win_ptr);
	if (key == 53)
		exit (0);
	if (key == 69 || key == 78)
		draw (tmp->win, to_center(tmp->win, zoom(&tmp->win, tmp->arr, key)));
		// {
	// 	zoom(&tmp->win, tmp->arr, key);
	// 	draw(tmp->win, zoom(&tmp->win, tmp->arr, key));
	// }
	if (key == 13 || key == 1)
	{
		draw(tmp->win, to_center(tmp->win, move_x(&tmp->win, tmp->arr, key)));
	// if (key == 2 || key == 0)
	// 	draw(tmp->win, to_center(tmp->win, move_y(&tmp->win, tmp->arr, key)));
	// if (key == 12 || key == 14)
	// 	draw(tmp->win, to_center(tmp->win, move_z(&tmp->win, tmp->arr, key)));
	}
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
	t_coords	**arr;
	t_window	*win;
	param		*tmp;
	int			i;

	i = 0;
	argc = 0;
	win = (t_window *)malloc(sizeof(t_window));
	arr = parsing(argv[1], &win);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGTH, "mlx 42");
	//draw(win, arr);
	draw(win, to_center(win, arr));
	tmp = (param *)malloc(sizeof(param));
	tmp->arr = arr;
	tmp->win = win;
	mlx_hook(win->win_ptr, 2, 0, deal_key, tmp);
	mlx_loop(win->mlx_ptr);
	return (0);
}
