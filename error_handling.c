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

#include "fdf.h"

void	error_handling(int res)
{
	if (res == 1)
		perror("Error");
	if (res == 2)
	{
		ft_putstr("Wrong number of arguments!\n");
		ft_putstr("usage: ./fdf name_of_map.fdf\n");
	}
	if (res == 3)
		ft_putstr("Error: empty file");
	if (res == 4)
		ft_putstr("Error, wrong number of columns!\n");
	if (res == 5)
		ft_putstr("Wrong input!\n");
	exit(1);
}

int		count_words(char const *s, char c)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		num++;
	}
	return (num);
}

void	columns(char *line)
{
	int		i;
	int		res;
	char	**arr;

	i = 0;
	if (line[0] != ' ' && line[0] != '-' && !ft_isdigit(line[0]))
		error_handling(5);
	arr = ft_strsplit(line, '\n');
	while (arr[i] != 0)
	{
		if (i == 0)
			res = count_words(arr[i], ' ');
		if (res != (int)count_words(arr[i], ' '))
			error_handling(4);
		free(arr[i]);
		i++;
	}
	free(arr);
}
