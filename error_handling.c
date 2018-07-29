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

void	columns(char *line)
{
	int		i;
	int		j;
	int		sp;

	i = -1;
	sp = 0;
	if (line[0] < 48 || line[0] > 57)
		error_handling(5);
	while (line[++i] != '\n')
		if (line[i] == ' ')
			sp++;
	i = -1;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && line[i] == ' ')
			j++;
		if (line[i] == '\n')
			j = 0;
		else if (line[i] == '\n' && j != sp)
			error_handling(4);
	}
}
