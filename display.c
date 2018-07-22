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

void	display(t_window *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 10, 0xFFFFFF,
	"Move the image up: 9");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 40, 0xFFFFFF,
	"Move the image down: 3");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 70, 0xFFFFFF,
	"Move the image left: <");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 100, 0xFFFFFF,
	"Move the image right: >");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 130, 0xFFFFFF,
	"Rotate along the x-axis: 1 / 7");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 160, 0xFFFFFF,
	"Rotate along the y-axis: 4 / 5");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 190, 0xFFFFFF,
	"Rotate along the z-axis: 2 / 8");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 220, 0xFFFFFF,
	"Enlarge the image: +");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 250, 0xFFFFFF,
	"Squeeze the image: -");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 280, 0xFFFFFF,
	"Increase the height: /\\");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 310, 0xFFFFFF,
	"Decrease the height: \\/");
}