/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:58:02 by omaslova          #+#    #+#             */
/*   Updated: 2018/07/09 15:58:08 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX(x, y) ((x) > (y)) ? (x) : (y)
# define POS(x) (x >= 0 ? 1 : -1)
# define WIDTH win->width
# define HEIGTH win->heigth
# define R_x win->corn_x
# define R_y win->corn_y
# define R_z win->corn_z
# define HIGH win->high
# define SCALE win->scale
# define MOVE_RIGHT win->move_right
# define MOVE_UP win->move_up
//# define COLOR win->arr->color
# include "get_next_line.h" 
# include <math.h>
# include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "./libft/libft.h"

typedef struct		s_coords
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_coords;

typedef struct		s_alg
{
	int				d_x;
	int				d_y;
	int				len_x;
	int				len_y;
	int				length;
	int				err;
	int				step;
}					t_alg;

typedef struct		s_window
{
	void			*win_ptr;
	void			*mlx_ptr;
	float			scale;
	float			corn_x;
	float			corn_y;
	float			corn_z;
	int				high;
	int				move_right;
	int				move_up;
	int				rows;
	int				columns;
	int				width;
	int				heigth;
	t_coords		**arr;
	t_coords		**mod_arr;
}					t_window;

t_coords			**parsing(char *argv, t_window **win);
void				print_coords(t_coords *dot, t_window *win);
void				print_coords_one(t_coords dot);
void				algoritm(t_window *win, t_coords start, t_coords end);
void				draw(t_window *win, t_coords **arr);
void				display(t_window *win);
t_coords			**convert(t_window *win);
t_coords			**to_center(t_window *win, t_coords **arr);
t_coords			**move_right(t_window *win);

#endif
