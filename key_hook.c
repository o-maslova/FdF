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

t_coords	**zoom(t_window **win, t_coords **arr, int key)
{
//	t_coords		**tmp;
	int i;
	int j;

	i = 0;
	//tmp = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
	while (i < (*win)->rows)
	{
		j = 0;
	//	tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
		//(*win)->scale += (*win)->scale;
		while (j < (*win)->columns)
		{
			if (key == 78)
			{
				arr[i][j].x = arr[i][j].x * (*win)->scale;
				arr[i][j].y = arr[i][j].y * (*win)->scale;
			}
			if (key == 69)
			{
				arr[i][j].x = arr[i][j].x / (*win)->scale;
				arr[i][j].y = arr[i][j].y / (*win)->scale;
			}
			//print_coords_one(arr[i][j]);
			j++;
		}
		i++;
	}
	return (arr);
}

t_coords	**move_x(t_window **win, t_coords **arr, int key)
{
	t_coords		**tmp;
	int				i;
	int				j;
	int				temp;
	int				temp2;

	if (key == 13)
		(*win)->corn += 0.2;
	if (key == 1)
		(*win)->corn -= 0.2;
	i = 0;
	tmp = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
	while (i < (*win)->rows)
	{
		j = 0;
		tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
		while (j < (*win)->columns)
		{
			arr[i][j].x = arr[i][j].x;
			temp = arr[i][j].y;
			arr[i][j].y = temp * cos((*win)->corn) + arr[i][j].z * sin((*win)->corn);
			temp2 = arr[i][j].z;
			arr[i][j].z = temp * sin((*win)->corn) + temp2 * cos((*win)->corn);
			j++;
		}
		i++;
	}
	return (arr);
}

t_coords	**move_y(t_window **win, t_coords **arr, int key)
{
	t_coords		**tmp;
	int			i;
	int			j;

	if (key == 0)
		(*win)->corn += 0.2;
	if (key == 2)
		(*win)->corn -= 0.2;
	i = 0;
	tmp = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
	while (i < (*win)->rows)
	{
		j = 0;
		tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
		while (j < (*win)->columns)
		{
			tmp[i][j].x = arr[i][j].x * cos((*win)->corn) + arr[i][j].z * sin((*win)->corn);
			tmp[i][j].y = arr[i][j].y;
			tmp[i][j].z = -arr[i][j].x * sin((*win)->corn) + arr[i][j].z * cos((*win)->corn);
			j++;
		}
		i++;
	}
	return (tmp);
}

t_coords	**move_z(t_window **win, t_coords **arr, int key)
{
	
	t_coords		**tmp;
	int			i;
	int			j;

	if (key == 12)
		(*win)->corn += 0.2;
	if (key == 14)
		(*win)->corn -= 0.2;
	i = 0;
	tmp = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
	while (i < (*win)->rows)
	{
		j = 0;
		tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
		while (j < (*win)->columns)
		{
			tmp[i][j].x = arr[i][j].x * cos((*win)->corn) - arr[i][j].y * sin((*win)->corn);
			tmp[i][j].y = arr[i][j].x * sin((*win)->corn) + arr[i][j].y * cos((*win)->corn);
			tmp[i][j].z = arr[i][j].z;
			j++;
		}
		i++;
	}
	return (tmp);
}