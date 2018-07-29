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

int		that_step(int start_col, t_color *step)
{
	int		tmp;
	int		res;
	t_color	*grad;

	tmp = 0x0000FF;
	grad = (t_color *)malloc(sizeof(t_color));
	grad->blue = start_col & tmp;
	tmp = tmp << 8;
	grad->green = (start_col & tmp) >> 8;
	tmp = tmp << 8;
	grad->red = (start_col & tmp) >> 16;
	res = (grad->blue + step->blue_step & 255);
	res = res + ((grad->green + step->green_step & 255) << 8);
	res = res + ((grad->red + step->red_step & 255) << 16);
	free(grad);
	return (res);
}

void	common_step(int start_col, int end_col, int len, t_color **col)
{
	int tmp;
	int red;
	int green;
	int blue;

	(*col) = (t_color *)malloc(sizeof(t_color));
	tmp = 0x0000FF;
	(*col)->blue = start_col & tmp;
	blue = end_col & tmp;
	tmp = tmp << 8;
	(*col)->green = (start_col & tmp) >> 8;
	green = (end_col & tmp) >> 8;
	tmp = tmp << 8;
	(*col)->red = (start_col & tmp) >> 16;
	red = (end_col & tmp) >> 16;
	(*col)->red_step = ((*col)->red - red) / len;
	(*col)->green_step = ((*col)->green - green) / len;
	(*col)->blue_step = ((*col)->blue - blue) / len;
	(*col)->red_step = -(*col)->red_step;
	(*col)->green_step = -(*col)->green_step;
	(*col)->blue_step = -(*col)->blue_step;
}

void	draw_vert_line(t_window *win, t_coords dot, t_alg *line, t_color *col)
{
	int	x;
	int	y;
	int	color;

	x = dot.x;
	y = dot.y;
	color = dot.color;
	line->err = line->len_y * -1;
	line->length += 1;
	while (line->length--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, dot.color);
		y += line->d_y;
		line->err += 2 * line->len_x;
		if (line->err > 0)
		{
			line->err -= 2 * line->len_y;
			x += line->d_x;
		}
		dot.color = that_step(dot.color, col);
	}
}

void	draw_horiz_line(t_window *win, t_coords dot, t_alg *line, t_color *col)
{
	int	x;
	int	y;
	int	color;

	x = dot.x;
	y = dot.y;
	color = dot.color;
	line->err = line->len_x * -1;
	line->length += 1;
	while (line->length--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, dot.color);
		x += line->d_x;
		line->err += 2 * line->len_y;
		if (line->err > 0)
		{
			line->err -= 2 * line->len_x;
			y += line->d_y;
		}
		dot.color = that_step(dot.color, col);
	}
}

void	algoritm(t_window *win, t_coords start, t_coords end)
{
	t_alg	*line;
	t_color	*col;
	int		x;
	int		y;

	x = start.x;
	y = start.y;
	line = (t_alg *)malloc(sizeof(t_alg));
	line->len_x = fabsf(end.x - x);
	line->len_y = fabsf(end.y - y);
	line->length = MAX(line->len_x, line->len_y);
	line->d_x = POS(end.x - start.x);
	line->d_y = POS(end.y - start.y);
	common_step(start.color, end.color, line->length + 1, &col);
	if (line->length == 0)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, start.color);
	if (line->len_y <= line->len_x)
		draw_horiz_line(win, start, line, col);
	else
		draw_vert_line(win, start, line, col);
	free(line);
	free(col);
}
