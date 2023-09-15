/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:51 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:51 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*init_fdf(char *buffer)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof (t_fdf));
	if (!fdf)
		print_error(MLC_ERROR);
	fdf->position = NULL;
	fdf->control = init_control();
	fdf->height = get_height(buffer);
	fdf->width = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->error = 0;
	fdf->delta_x = 0;
	fdf->delta_y = 0;
	fdf->slope_x = 0;
	fdf->slope_y = 0;
	fdf->projection = ISO;
	return (fdf);
}

void	init_mlx(t_data *data, char *buffer)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		print_error(MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT,
			W_NAME);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		print_error(MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->fdf = init_fdf(buffer);
}

t_control	*init_control(void)
{
	t_control	*new_control;

	new_control = (t_control *)malloc(sizeof(t_control));
	if (!new_control)
		print_error(MLX_ERROR);
	new_control->zoom = 25;
	new_control->zout = 10;
	new_control->color = 0;
	new_control->x_angle = 0;
	new_control->y_angle = 0;
	new_control->z_angle = 0;
	new_control->shift_x = W_HEIGHT / 2;
	new_control->shift_y = W_WIDTH / 2;
	return (new_control);
}

void	reset_control(t_fdf *fdf)
{
	fdf->control->shift_x = W_WIDTH / 2;
	fdf->control->shift_y = W_HEIGHT / 2;
	fdf->control->zoom = 25;
	fdf->control->zout = 10;
	fdf->control->color = 0;
	fdf->control->x_angle = 0;
	fdf->control->z_angle = 0;
	fdf->control->y_angle = 0;
}

void	check_fdf(t_fdf *fdf)
{
	ft_printf("height: \t\t|&d|\n", fdf->height);
	ft_printf("width: \t\t|&d|\n", fdf->width);
	ft_printf("delta_x: \t|%d|\n", fdf->delta_x);
	ft_printf("delta_y: \t|%d|\n", fdf->delta_y);
	ft_printf("slope_x: \t|%d|\n", fdf->slope_x);
	ft_printf("slope_y: \t|%d|\n", fdf->slope_y);
	ft_printf("x:\t\t|%d|\n", fdf->x);
	ft_printf("y:\t\t|%d|\n", fdf->y);
	ft_printf("error:\t\t|%d|\n\n", fdf->error);
}
