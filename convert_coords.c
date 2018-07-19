#include "fdf.h"

t_coords	*convert_x(t_coords *xyz, t_coords *xy)
{
	double y;

	y = xyz->y;
	xy->x = xyz->x;
	xy->y = y * cos(R_x) + xyz->z * sin(R_x);
	xy->z = xyz->z * cos(R_x) - y * sin(R_x);
	return(xy);
}

t_coords	*convert_y(t_coords *xyz, t_coords *xy)
{
	double x;

	x = xyz->x;
	xy->x = x * cos(R_y) - xyz->z * sin(R_y);
	xy->y = xyz->y;
	xy->z = xyz->z * cos(R_y) + x * sin(R_y);
	return (xy);
}

t_coords	*convert_z(t_coords *xyz, t_coords *xy)
{
	double x;
	double y;

	x = xyz->x;
	y = xyz->y;
	xy->x = x * cos(R_z) - y * sin(R_z);
	xy->y = x * sin(R_z) + y * cos(R_z);
	xy->z = xyz->z;
	return (xy);
}

t_coords	**convert(t_window *win)
{
	t_coords **xyz;
	int i;
	int j;

	i = 0;
	xyz = (t_coords **)malloc(sizeof(t_coords *) * win->rows);
	while (i < win->rows)
	{
		j = 0;
		xyz[i] = (t_coords *)malloc(sizeof(t_coords) * win->columns);
		while (j < win->columns)
		{
			xyz[i][j]
			j++;
		}
		i++;
	}
	return (xyz);
}