/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:54 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:54 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_altitude(int keysym, t_data *data)
{
	if (keysym == XK_s)
		data->fdf->control->zout -= 1;
	else if (keysym == XK_a)
		data->fdf->control->zout += 1;
	if (data->fdf->control->zout < 1)
		data->fdf->control->zout = 1;
	else if (data->fdf->control->zout > 100)
		data->fdf->control->zout = 100;
	reproject(data);
}

static void	set_projections(int keysym, t_data *data)
{
	if (keysym == XK_1)
		data->fdf->projection = ISO;
	else if (keysym == XK_2)
		data->fdf->projection = DIMETRIC;
	else if (keysym == XK_3)
		data->fdf->projection = CONIC;
	reproject(data);
}

static void	set_color_mode(t_data *data)
{
	data->fdf->control->color = (!data->fdf->control->color);
	reproject(data);
}

static void	set_angle(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->fdf->control->y_angle -= 5;
	else if (keysym == XK_Right)
		data->fdf->control->y_angle += 5;
	else if (keysym == XK_Up)
		data->fdf->control->x_angle -= 5;
	else if (keysym == XK_Down)
		data->fdf->control->x_angle += 5;
	reproject(data);
}

int	press_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_program(data);
	else if (keysym >= XK_1 && keysym <= XK_4)
		set_projections(keysym, data);
	else if (keysym == XK_a || keysym == XK_s)
		set_altitude(keysym, data);
	else if (keysym == XK_c)
		set_color_mode(data);
	else if (keysym >= XK_Left && keysym <= XK_Down)
		set_angle(keysym, data);
	else if (keysym == XK_d)
	{
		reset_control(data->fdf);
		reproject(data);
	}
	return (1);
}
