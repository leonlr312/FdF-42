/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:43 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:43 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	set_color_2(int z)
{
	if (z >= 8 || z <= -8)
		if (z >= 8)
			return (C_NIER_WHITE);
	else
		return (C_BLU);
	else if (z >= 4 || z >= -4)
		if (z >= 4)
			return (C_NIER_YELLOW);
	else
		return (C_ORG);
	else if (z >= 2 || z <= -2)
		if (z >= 2)
			return (C_NIER_BEIGE);
	else
		return (C_NIER_BROWN);
	else if (z > 0 || z < 0)
		if (z >= 2)
			return (C_NIER_TXT);
	else
		return (C_NIER_BROWN);
	else
		return (C_NIER_BROWN);
}

int	set_color(t_fdf *fdf, int z)
{
	if (!fdf->control->color)
		return (C_NIER_TXT);
	else
		return (set_color_2(z));
}

static int	get_light(int start, int end, double percentage)
{
	int	ret;

	ret = (int)(1 - percentage);
	return (ret * start + percentage * end);
}

static double	get_percent(int start, int end, int current)
{
	double	placemant;
	double	distance;

	placemant = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placemant / distance);
}

int	get_color(t_fdf *fdf, t_position *start, t_position *end)
{
	int	r;
	int	g;
	int	b;
	int	percentage;

	if (start->color == end->color)
		return (end->color);
	if (fdf->delta_x > fdf->delta_y)
		percentage = get_percent(start->ix, end->ix, fdf->x);
	else
		percentage = get_percent(start->iy, end->iy, fdf->y);
	r = get_light((start->color >> 16) & 0xFF,
			(end->color >> 16) & 0xFF, percentage);
	g = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage);
	b = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return (r << 16 | g << 8 | b);
}
