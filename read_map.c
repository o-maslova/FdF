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
	static int k;
	int i;

	i = 0;
	printf("---coords number %d---\n", k++);
	printf("x = %f  ", dot.x);
	printf("y = %f  ", dot.y);
	printf("z = %f\n", dot.z);
}

t_coords	**to_center(t_window *win)
{
	int i;
	int j;
	int len_x;
	int len_y;
	t_coords **tmp;

	i = 0;
	len_x = win->columns * (win->arr[0][1].x - win->arr[0][0].x);
	len_y = win->rows * (win->arr[1][0].y - win->arr[0][0].y);
	tmp = (t_coords **)malloc(sizeof(t_coords *) * win->rows);
	while (i < win->rows)
	{
		j = 0;
		tmp[i] = (t_coords *)malloc(sizeof(t_coords) * win->columns);
		while (j < win->columns)
		{
			tmp[i][j].x = win->arr[i][j].x + (WIDTH / 2) - (len_x / 2);
			tmp[i][j].y = win->arr[i][j].y + (HEIGTH / 2) - (len_y / 2);
			j++;
		}
		i++;
	}
	return (tmp);
}

t_coords	*fill_arr(char **arr, int k, t_window *win)
{
	int				i;
	t_coords		*pixel;

	i = 0;
	pixel = (t_coords *)malloc(sizeof(t_coords) * win->columns);
	while (arr[i] != 0)
	{
		pixel[i].x = i;
		pixel[i].y = k;
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
	//	print_coords(map[i], *win);
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
	// printf("%s\n", tmp);
	// printf("\n---------\n");
	(*win)->rows = find_rows(tmp);
	(*win)->columns = 0;
	(*win)->scale = 0.8;
	(*win)->arr = make_arr(tmp, win);
	(*win)->corn = 0.2;
	return ((*win)->arr);
}