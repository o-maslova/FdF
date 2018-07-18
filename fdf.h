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
# define ABS(x) (x < 0 ? -x : x)
# define MAX(x, y) ((x) > (y)) ? (x) : (y)
# define POS(x, y) ((x) < (y) ? 1 : -1)
# define WIDTH 1000
# define HEIGTH 1000
# include "get_next_line.h" 
# include <math.h>
# include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "./libft/libft.h"

typedef struct			s_coords
{
	float				x;
	float				y;
	float				z; 
}						t_coords;

typedef struct			s_alg
{
	int				d_x;
	int				d_y;
	int				len_x;
	int				len_y;
	int				length;
	int				err;
}						t_alg;

typedef struct			s_window
{
	void				*win_ptr;
	void				*mlx_ptr;
	float				scale;
	float				corn;
	int					rows;
	int					columns;
	t_coords			**arr;
}						t_window;

t_coords			**parsing(char *argv, t_window **win);
void				print_coords(t_coords *dot, t_window *win);
void				print_coords_one(t_coords dot);
void				algoritm(t_window *win, t_coords start, t_coords end);
void				draw(t_window *win, t_coords **arr);
t_coords			**to_center(t_window *win);
t_coords			**zoom(t_window *win, int key);
t_coords			**move_x(t_window **win, t_coords **arr, int key);
t_coords			**move_y(t_window **win, t_coords **arr, int key);
t_coords			**move_z(t_window **win, t_coords **arr, int key);

#endif
