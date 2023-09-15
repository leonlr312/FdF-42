/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:38:46 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:46 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_fdf(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (fdf->position[y])
	{
		x = 0;
		while (fdf->position[y][x])
		{
			free(fdf->position[y][x]);
			x++;
		}
		free(fdf->position[y]);
		y++;
	}
	free(fdf->position);
}

void	free_all(t_data *data)
{
	free(data->fdf->control);
	free_fdf(data->fdf);
}

void	print_error(char *error_msg)
{
	ft_printf(error_msg);
	exit(1);
}

int	end_program(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->legend.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->fdf->control);
	free_fdf(data->fdf);
	free(data->fdf);
	free(data);
	exit(0);
}
