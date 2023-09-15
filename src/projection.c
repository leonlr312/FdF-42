/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:59 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:59 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	radian_ang(int angle)
{
	return ((angle * M_PI) / 180);
}

static void	metric(t_fdf *fdf, t_position *position)
{
	int		ant_x;
	int		ant_y;
	double	rad;

	if (fdf->projection == 1)
		rad = radian_ang(30);
	else
		rad = radian_ang(15);
	ant_x = position->rx;
	ant_y = position->ry;
	position->ix = fdf->control->shift_x + (ant_x - ant_y) * cos(rad);
	position->iy = fdf->control->shift_y + (position->rz
			+ (ant_x + ant_y) * sin(rad));
	position->color = set_color(fdf, position->pz / fdf->control->zout);
}

static void	conic(t_fdf *fdf, t_position *position)
{
	int	ant_x;
	int	ant_y;

	ant_x = position->rx;
	ant_y = position->ry;
	position->ix = fdf->control->shift_x + ant_x;
	position->iy = fdf->control->shift_y + ant_y;
	position->color = set_color(fdf, position->pz / fdf->control->zout);
}

void	projection(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (fdf->projection == ISO || fdf->projection == DIMETRIC)
				metric(fdf, fdf->position[y][x]);
			else if (fdf->projection == CONIC)
				conic(fdf, fdf->position[y][x]);
			x++;
		}
		y++;
	}
}
