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

void	display_first(t_window *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 0, 0x9AB1B3,
	"* * * * * * * * * * * * * * *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 15, 0x9AB1B3,
	"*   MOVE:  up       up >    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 35, 0x9AB1B3,
	"*          down     down >  *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 50, 0x9AB1B3,
	"*          left        <    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 65, 0x9AB1B3,
	"*          right       >    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 80, 0x9AB1B3,
	"* ROTATE:  x-axis    a, d   *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 95, 0x9AB1B3,
	"*          y-axis    w, s   *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 110, 0x9AB1B3,
	"*          z-axis    q, e   *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 125, 0x9AB1B3,
	"* SCALE:   bigger      +    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 140, 0x9AB1B3,
	"*          smaller     -    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 155, 0x9AB1B3,
	"*  HIGH:  increase     7    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 170, 0x9AB1B3,
	"*         decrease     1    *");
}

void	display_second(t_window *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 185, 0x9AB1B3,
	"* COLOR:                    *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 185, 0x910D0D,
	"            red        R     ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 200, 0x9AB1B3,
	"*                           *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 200, 0x27964C,
	"           green       G     ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 215, 0x9AB1B3,
	"*                           *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 215, 0x41B0EE,
	"            blue       B     ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 230, 0x9AB1B3,
	"*                           *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 230, 0x9B11D1,
	"           purple      P     ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 245, 0x9AB1B3,
	"*                           *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 245, 0xEB7C21,
	"           orange      O     ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 265, 0x9AB1B3,
	"*the first view:     space  *");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 280, 0x9AB1B3,
	"* * * * * * * * * * * * * * *");
}
