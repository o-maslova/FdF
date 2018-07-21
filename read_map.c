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

void		print_coords(t_coords *dot, t_window *win)
{
	static int k;
	int i;

	i = 0;
	while (i < win->columns)
	{
		printf("---coords number %d---\n", k++);
		printf("x = %f  ", dot[i].x);
		printf("y = %f  ", dot[i].y);
		printf("z = %f\n", dot[i].z);
		i++;
	}
}

void		print_coords_one(t_coords dot)
{
	static int k = 0;
	int i;

	i = 0;
	printf("---coords number %d---\n", k++);
	printf("x = %f  ", dot.x);
	printf("y = %f  ", dot.y);
	printf("z = %f\n", dot.z);
}

t_coords	*fill_arr(char **arr, int k, t_window *win)
{
	int				i;
	t_coords		*pixel;

	i = 0;
	pixel = (t_coords *)malloc(sizeof(t_coords) * win->columns);
	while (arr[i] != 0)
	{
		pixel[i].x = i * 20;
		pixel[i].y = k * 20;
		pixel[i].z = ft_atoi(arr[i]);
		i++;		
	}
	return (pixel);
}

int			find_rows(char *line)
{
	int i;
	int row;
	char *tmp;
	char *ptr;

	i = 0;
	row = 0;
	tmp = line;
	while (tmp)
	{
		if ((ptr = ft_strchr(tmp, '\n')) != NULL)
		{
			row++;
			ptr++;
			tmp = ptr;
		}
		else
			break ;
	}
	return (row);
}

int			find_columns(char **line)
{
	int i;
	char **tmp;

	i = 0;
	tmp = line;
	while (tmp[i] != 0)
		i++;
	return (i);	
}

t_coords	**make_arr(char *line, t_window **win)
{
	int			i;
	char		**arr_row;
	char		**arr_clmn;
	
	i = 0;
	(*win)->arr = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
	arr_row = ft_strsplit(line, '\n');
	while (i < (*win)->rows)
	{
		arr_clmn = ft_strsplit(arr_row[i], ' ');
		if ((*win)->columns == 0)
			(*win)->columns = find_columns(arr_clmn);
		else if ((*win)->columns != find_columns(arr_clmn))
		{
			printf("Error");
			return (0);
		}
		(*win)->arr[i] = fill_arr(arr_clmn, i, *win);
		i++;
	}
	return ((*win)->arr);
}

t_coords		**parsing(char *argv, t_window **win)
{
	int			i;
	int			fd;
	char		*line;
	char		*tmp;

	i = 0;
	tmp = "";
	fd = open(argv, O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strjoin(tmp, line);
		tmp = ft_strjoin(tmp, "\n");
	}
	(*win)->rows = find_rows(tmp);
	(*win)->columns = 0;
	(*win)->scale = 1;
	(*win)->arr = make_arr(tmp, win);
	(*win)->corn_x = 1;
	(*win)->corn_y = 0.5;
	(*win)->corn_z = 0;
	(*win)->high = 2;
	(*win)->move_right = 0;
	(*win)->move_up = 0;
	return ((*win)->arr);
}