/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:06 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:06 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_position *position, double ang)
{
	int	y;

	y = position->ry;
	position->ry = y * cos(ang) + position->rz * sin(ang);
	position->rz = -y * sin(ang) + position->rz * cos(ang);
}

static void	rotate_y(t_position *position, double ang)
{
	int	x;

	x = position->rx;
	position->rx = x * cos(ang) + position->rz * sin(ang);
	position->rz = -x * sin(ang) + position->rz * cos(ang);
}

static void	rotate_z(t_position *position, double ang)
{
	int	x;
	int	y;

	x = position->rx;
	y = position->ry;
	position->rx = x * cos(ang) - y * sin(ang);
	position->ry = x * sin(ang) + y * cos(ang);
}

void	rotate(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdf->position[y][x]->rx = fdf->position[y][x]->px;
			fdf->position[y][x]->ry = fdf->position[y][x]->py;
			fdf->position[y][x]->rz = fdf->position[y][x]->pz;
			fdf->position[y][x]->rx *= fdf->control->zoom;
			fdf->position[y][x]->ry *= fdf->control->zoom;
			fdf->position[y][x]->rz *= fdf->control->zoom / fdf->control->zout;
			fdf->position[y][x]->rx -= (fdf->width * fdf->control->zoom) / 2;
			fdf->position[y][x]->ry -= (fdf->height * fdf->control->zoom) / 2;
			rotate_x(fdf->position[y][x], radian_ang(fdf->control->x_angle));
			rotate_y(fdf->position[y][x], radian_ang(fdf->control->y_angle));
			rotate_z(fdf->position[y][x], radian_ang(fdf->control->z_angle));
			x++;
		}
		y++;
	}
}
