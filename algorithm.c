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

void		draw_vert_line(t_window *win, t_coords dot, t_alg *line)
{
	float x;
	float y;

	x = dot.x;
	y = dot.y;
	line->length += 1;
	while (line->length--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0xFF0000);
		y += line->d_y;
		line->err += 2 * line->len_x;
		if (line->err > 0)
		{
			line->err -= 2 * line->len_y;
			x += line->d_x;
		}
	}
}

void		draw_horiz_line(t_window *win, t_coords dot, t_alg *line)
{
	float x;
	float y;

	x = dot.x;
	y = dot.y;
	line->length += 1;
	while (line->length--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0xFF0000);
		x += line->d_x;
		line->err += 2 * line->len_y;
		if (line->err > 0)
		{
			line->err -= 2 * line->len_x;
			y += line->d_y;
		}
	}
}

void		algoritm(t_window *win, t_coords start, t_coords end)
{
	t_alg		*line;
	float		x;
	float		y;
//	int		e2;

	x = start.x;
	y = start.y;
	line = (t_alg *)malloc(sizeof(t_alg));
	line->len_x = ABS(end.x - x);
	line->len_y = ABS(end.y - y);
	//line->err = line->len_x / line->len_y;
	line->length = MAX(line->len_x, line->len_y);
	//line->len_x = 500 - (win->columns / 2 * line->length);
	line->d_x = POS(x, end.x);
	line->d_y = POS(y, end.y);
	line->err = (line->len_x > line->len_y ? line->len_x : -line->len_y);
	//e2 = line->err;
	if (line->length == 0)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0xFF0000);
	else if (line->len_y <= line->len_x)
	{
		line->err = -line->len_x;
		draw_horiz_line(win, start, line);
	}
	else
	{
		line->err = -line->len_y;
		draw_vert_line(win, start, line);
	}
}
