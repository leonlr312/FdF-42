/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:57 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:57 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_zoom(int button, t_data *data)
{
	if (button == 4)
	{
		data->fdf->control->zoom *= 1.2;
		reproject(data);
	}
	else if (button == 5)
	{
		data->fdf->control->zoom /= 1.2;
		reproject(data);
	}
	if (data->fdf->control->zoom < 1)
		data->fdf->control->zoom = 1;
}

static int	set_position(int x, int y, t_data *data)
{
	data->fdf->control->shift_x = x;
	data->fdf->control->shift_y = y;
	reproject(data);
	return (1);
}

int	press_mouse(int button, int x, int y, t_data *data)
{
	if (button == 4 || button == 5)
		set_zoom(button, data);
	else if (button == 1)
		set_position(x, y, data);
	return (1);
}
