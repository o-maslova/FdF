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

t_coords	*fill_arr(char **arr, int k, t_window *win)
{
	int			i;
	t_coords	*pixel;

	i = 0;
	pixel = (t_coords *)malloc(sizeof(t_coords) * win->columns);
	while (arr[i] != 0)
	{
		pixel[i].x = i;
		pixel[i].y = k;
		pixel[i].z = ft_atoi(arr[i]);
		pixel[i].color = atoi_base(arr[i], 16);
		if (pixel[i].color == 0)
			pixel[i].color = COLOR;
		i++;
	}
	return (pixel);
}

int			find_rows(char *line)
{
	int		i;
	int		row;
	char	*tmp;
	char	*ptr;

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
	int		i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}

t_coords	**make_arr(char *line, t_window **win)
{
	int		i;
	int		j;
	char	**arr_row;
	char	**arr_clmn;

	i = 0;
	j = 0;
	(*win)->arr = (t_coords **)malloc(sizeof(t_coords *) * (*win)->rows);
	arr_row = ft_strsplit(line, '\n');
	free(line);
	while (i < (*win)->rows)
	{
		arr_clmn = ft_strsplit(arr_row[i], ' ');
		free(arr_row[i]);
		while (arr_clmn[j] != 0)
			j++;
		if ((*win)->columns == 0)
			(*win)->columns = j;
		(*win)->arr[i] = fill_arr(arr_clmn, i, *win);
		memory_free(arr_clmn);
		i++;
	}
	free(arr_row);
	return ((*win)->arr);
}

t_coords	**parsing(char *argv, t_window **win)
{
	int		fd;
	int		gnl_res;
	char	*line;
	char	*tmp;

	fd = open(argv, O_RDONLY);
	while ((gnl_res = get_next_line(fd, &line)) > 0)
	{
		tmp = cancat(line, &tmp);
		if (*line == '\0')
			error_handling(5);
		free(line);
	}
	if (gnl_res == 0 && tmp == NULL)
		error_handling(3);
	if (gnl_res < 0)
		error_handling(1);
	tmp[ft_strlen(tmp)] = '\n';
	(*win)->rows = find_rows(tmp);
	(*win)->columns = 0;
	(*win)->color = 0xFFFFFF;
	columns(tmp);
	(*win)->arr = make_arr(tmp, win);
	close(fd);
	return ((*win)->arr);
}
