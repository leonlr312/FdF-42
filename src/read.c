/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:01 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:01 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(t_fdf *fdf, char **values, int n_line)
{
	int	x;

	x = 0;
	while (values[x])
		x++;
	if (x == 0 || (n_line > 0 && x != fdf->width))
		print_error(MAP_ERROR);
	if (x > fdf->width)
		fdf->width = x;
	return (x);
}

void	lide_value(char	**values, t_fdf *fdf, int y)
{
	int	x;
	int	width;

	x = 0;
	width = get_width(fdf, values, y);
	fdf->position[y] = (t_position **)malloc(sizeof(t_position *)
			* (width + 1));
	if (!fdf->position)
		print_error(MLC_ERROR);
	while (values[x] != NULL)
	{
		fdf->position[y][x] = (t_position *)malloc(sizeof(t_position));
		if (!fdf->position)
			print_error(MLC_ERROR);
		fdf->position[y][x]->px = x;
		fdf->position[y][x]->py = y;
		if (values[x] == NULL)
			print_error(MLC_ERROR);
		fdf->position[y][x]->pz = ft_atoi(values[x]);
		free(values[x]);
		x++;
	}
	free(values);
	fdf->position[y][x] = NULL;
}

void	get_line(t_fdf *fdf, char *buffer)
{
	int		i;
	int		fd;
	char	*line;
	int		number_line;
	char	**values;

	i = 0;
	line = NULL;
	number_line = fdf->height;
	fd = open(buffer, O_RDONLY);
	if (fd == -1)
		print_error(OPN_ERROR);
	while (i < number_line)
	{
		line = ft_get_next_line(fd);
		if (!line)
			print_error(GNL_ERROR);
		values = ft_split(line, ' ');
		lide_value(values, fdf, i);
		free(line);
		i++;
	}
	close(fd);
	fdf->position[number_line] = NULL;
}

void	gnl_read(t_fdf *fdf, char *buffer)
{
	fdf->position = (t_position ***)malloc(sizeof(t_position **)
			* (fdf->height + 1));
	if (!fdf->position)
		print_error(MLC_ERROR);
	get_line(fdf, buffer);
}

int	get_height(char *buffer)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(buffer, O_RDONLY);
	if (fd == -1)
		print_error(OPN_ERROR);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	return (height);
}
