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

t_coords	**zoom(t_window *win, int key)
{
	int i;
	int j;

	i = 0;
	while (i < win->rows)
	{
		j = 0;
		while (j < win->columns)
		{
			if (key == 78)
			{
				win->arr[i][j].x = win->arr[i][j].x * win->scale;
				win->arr[i][j].y = win->arr[i][j].y * win->scale;
			}
			if (key == 69)
			{
				win->arr[i][j].x = win->arr[i][j].x / win->scale;
				win->arr[i][j].y = win->arr[i][j].y / win->scale;
			}
			//print_coords_one(arr[i][j]);
			j++;
		}
		i++;
	}
	return (win->arr);
}

void		move_x(t_window **win, double corn)
{
	t_coords		*tmp;
	int				i;
	int				j;

	i = 0;
	tmp = (t_coords *)malloc(sizeof(t_coords));
	//key = 0;
//	tmp->corn = 0;
	// if (key == 13)
	// 	tmp->corn += 0.1;
	// if (key == 1)
	// 	(*win)->corn -= 0.1;
	while (i < (*win)->rows)
	{
		j = 0;
	//	tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
		while (j < (*win)->columns)
		{
			tmp->x = (*win)->arr[i][j].x;
			tmp->y = (*win)->arr[i][j].y * cos(corn) + (*win)->arr[i][j].z * sin(corn);
			tmp->z = (*win)->arr[i][j].z * cos(corn) - (*win)->arr[i][j].y * sin(corn);
			(*win)->arr[i][j].x = tmp->x;
			(*win)->arr[i][j].y = tmp->y;
			(*win)->arr[i][j].z = tmp->z;
			// tmp2->x = tmp->x * cos(tmp2->corn) - tmp->z * sin(tmp2->corn);
			// tmp2->y = tmp->y;
			// tmp2->z = tmp->z * cos(tmp->corn) + tmp->x * sin(tmp->corn);
			// (*win)->arr[i][j].x = tmp2->x * cos(tmp->corn) + tmp2->y * sin(tmp->corn);
			// (*win)->arr[i][j].y = tmp2->y * cos(tmp->corn) - tmp2->x * sin(tmp->corn);
			
			// (*win)->arr[i][j].x = (*win)->arr[i][j].x;
			// temp = (*win)->arr[i][j].y;
			// (*win)->arr[i][j].y = temp * cos((*win)->corn) + (*win)->arr[i][j].z * sin((*win)->corn);
			// temp2 = (*win)->arr[i][j].z;
			// (*win)->arr[i][j].z = temp * sin((*win)->corn) + temp2 * cos((*win)->corn);
			j++;
		}
		i++;
	}
//	return ((*win)->arr);
}

void		move_y(t_window **win, double corn)
{
	t_coords		*tmp;
	int			i;
	int			j;

	i = 0;
	tmp = (t_coords *)malloc(sizeof(t_coords));
//	tmp->corn = 0;
	// if (key == 0)
	// 	(*win)->corn += 0.2;
	// if (key == 2)
	// 	(*win)->corn -= 0.2;
	while (i < (*win)->rows)
	{
		j = 0;
		//tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
		while (j < (*win)->columns)
		{
			tmp->x = (*win)->arr[i][j].x * cos(corn) + (*win)->arr[i][j].z * sin(corn);
			tmp->y = (*win)->arr[i][j].y;
			tmp->z = (*win)->arr[i][j].z * cos(corn) - (*win)->arr[i][j].x * sin(corn);
			(*win)->arr[i][j].x = tmp->x;
			(*win)->arr[i][j].y = tmp->y;
			(*win)->arr[i][j].z = tmp->z;

			// tmp[i][j].x = arr[i][j].x * cos((*win)->corn) + arr[i][j].z * sin((*win)->corn);
			// tmp[i][j].y = arr[i][j].y;
			// tmp[i][j].z = -arr[i][j].x * sin((*win)->corn) + arr[i][j].z * cos((*win)->corn);
			j++;
		}
		i++;
	}
//	return (tmp);
}

// void		move_z(t_window **win, int key)
// {
	
// 	t_coords		**tmp;
// 	int			i;
// 	int			j;

// 	if (key == 12)
// 		(*win)->corn += 0.2;
// 	if (key == 14)
// 		(*win)->corn -= 0.2;
// 	i = 0;
// 	tmp = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
// 	while (i < (*win)->rows)
// 	{
// 		j = 0;
// 		tmp[i] = (t_coords *)malloc(sizeof(t_coords) * (*win)->columns);
// 		while (j < (*win)->columns)
// 		{
// 			tmp[i][j].x = arr[i][j].x * cos((*win)->corn) - arr[i][j].y * sin((*win)->corn);
// 			tmp[i][j].y = arr[i][j].x * sin((*win)->corn) + arr[i][j].y * cos((*win)->corn);
// 			tmp[i][j].z = arr[i][j].z;
// 			j++;
// 		}
// 		i++;
// 	}
// //	return (tmp);
// }