/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:40 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:40 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_low(t_data *data, t_position *start, t_position *end)
{
	int	i;

	i = 0;
	while (i++ <= data->fdf->delta_x)
	{
		img_pix_put(&data->img, data->fdf->x, data->fdf->y,
			get_color(data->fdf, start, end));
		if (data->fdf->error > 0)
		{
			data->fdf->y += data->fdf->slope_y;
			data->fdf->error = data->fdf->error + 2
				* (data->fdf->delta_y - data->fdf->delta_x);
		}
		else
			data->fdf->error = data->fdf->error + 2 * data->fdf->delta_y;
		data->fdf->x += data->fdf->slope_x;
	}
}

static void	set_high(t_data *data, t_position *start, t_position *end)
{
	int	i;

	i = 0;
	while (i++ <= data->fdf->delta_y)
	{
		img_pix_put(&data->img, data->fdf->x, data->fdf->y,
			get_color(data->fdf, start, end));
		if (data->fdf->error > 0)
		{
			data->fdf->x += data->fdf->slope_x;
			data->fdf->error = data->fdf->error + 2
				* (data->fdf->delta_x - data->fdf->delta_y);
		}
		else
			data->fdf->error = data->fdf->error + 2 * data->fdf->delta_x;
		data->fdf->y += data->fdf->slope_y;
	}
}

static void	get_args(t_fdf *fdf, t_position *start, t_position *end)
{
	fdf->delta_x = ft_abs(end->ix - start->ix);
	fdf->delta_y = ft_abs(end->iy - start->iy);
	if (end->ix >= start->ix)
		fdf->slope_x = 1;
	else
		fdf->slope_x = -1;
	if (end->iy >= start->iy)
		fdf->slope_y = 1;
	else
		fdf->slope_y = -1;
	fdf->x = start->ix;
	fdf->y = start->iy;
	if (fdf->delta_x > fdf->delta_y)
		fdf->error = 2 * (fdf->delta_y - fdf->delta_x);
	else
		fdf->error = 2 * (fdf->delta_x - fdf->delta_y);
}

static void	line_a_line(t_data *data, t_position *start, t_position *end)
{
	get_args(data->fdf, start, end);
	if (data->fdf->delta_x > data->fdf->delta_y)
		set_low(data, start, end);
	else
		set_high(data, start, end);
}

void	set_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->fdf->height)
	{
		x = 0;
		while (x < data->fdf->width)
		{
			if (x < data->fdf->width - 1)
				line_a_line(data, data->fdf->position[y][x],
					data->fdf->position[y][x + 1]);
			if (y < data->fdf->height - 1)
				line_a_line(data, data->fdf->position[y][x],
					data->fdf->position[y + 1][x]);
			x++;
		}
		y++;
	}
}
