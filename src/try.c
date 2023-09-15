/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:09 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:09 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_back(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

static void	draw_legend_2(t_data *data, int y)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 35, C_WHT,
		"PROJECTIONS:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_NIER_ORANGE,
		"ISOMETRIC: '1'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_NIER_ORANGE,
		"DIMETRIC: '2'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_NIER_ORANGE,
		"CONIC: '3'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (L_WIDTH - 80),
		(W_HEIGHT - 20), BLACK_PIXEL, "by: leoda-lu");
}

void	draw_legend(t_data *data)
{
	int	y;

	y = 0;
	data->legend.mlx_img = mlx_new_image(data->mlx_ptr, L_WIDTH, W_HEIGHT);
	data->legend.addr = mlx_get_data_addr(data->legend.mlx_img,
			&data->legend.bpp, &data->legend.line_len, &data->legend.endian);
	render_back(&data->legend, C_NIER_D_GRAY);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->legend.mlx_img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20,
		C_WHT, "HOW TO USE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25,
		C_NIER_ORANGE, "COLOR: 'C' Key");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25,
		C_NIER_ORANGE, "ZOOM: Scroll Mouse");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25,
		C_NIER_ORANGE, "MOVE: Right Click");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25,
		C_NIER_ORANGE, "ALTITUDE: 'A' and 'S' Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25,
		C_NIER_ORANGE, "ROTATE: Arrow Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25,
		C_NIER_ORANGE, "RESET: 'D' Key");
	draw_legend_2(data, y);
}
