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

void		turn(int key, t_window *win)
{
	if (key == 13)
		R_X += 0.2;
	if (key == 1)
		R_X -= 0.2;
	if (key == 2)
		R_Y += 0.2;
	if (key == 0)
		R_Y -= 0.2;
	if (key == 14)
		R_Z += 0.2;
	if (key == 12)
		R_Z -= 0.2;
}

void		move(int key, t_window *win)
{
	if (key == 124)
		MOVE_RIGHT += 10;
	if (key == 123)
		MOVE_RIGHT -= 10;
	if (key == 125)
		MOVE_UP += 10;
	if (key == 126)
		MOVE_UP -= 10;
	if (key == 89)
		HIGH += 1;
	if (key == 83)
		HIGH -= 1;
}

void		color(int key, t_window *win)
{
	if (key == 15)
		COLOR = 0x910D0D;
	if (key == 5)
		COLOR = 0x27964C;
	if (key == 11)
		COLOR = 0x41B0EE;
	if (key == 15)
		COLOR = 0x910D0D;
	if (key == 35)
		COLOR = 0x9B11D1;
	if (key == 31)
		COLOR = 0xEB7C21;
}

t_coords	**gradient(t_window **win)
{
	int i;
	int j;

	i = 0;
	(*win)->flag = 1;
	while (++i < (*win)->rows)
	{
		j = 0;
		while (++j < (*win)->columns)
			if ((*win)->arr[i][j].z > (*win)->max)
				(*win)->max = (*win)->arr[i][j].z;
	}
	i = -1;
	while (++i < (*win)->rows)
	{
		j = -1;
		while (++j < (*win)->columns)
		{
			if ((*win)->arr[i][j].z == (*win)->max)
				(*win)->mod_arr[i][j].color = (*win)->color;
			else
				(*win)->mod_arr[i][j].color = 0xFFFFFF;
		}
	}
	return ((*win)->mod_arr);
}
