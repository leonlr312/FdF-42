/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:11 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:11 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(t_data *data)
{
	render_back(&data->img, BLACK_PIXEL);
	draw_legend(data);
	rotate(data->fdf);
	projection(data->fdf);
	set_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, L_WIDTH, 0);
	return (1);
}

void	print_points(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (fdf->position[i])
	{
		j = 0;
		while (fdf->position[i][j])
		{
			ft_printf("&d ", fdf->position[i][j]->pz);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*map;
	t_data	*data;

	if (argc != 2)
		print_error(USG_ERROR);
	map = argv[1];
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(OPN_ERROR);
	data = (t_data *)malloc(sizeof (t_data));
	init_mlx(data, argv[1]);
	gnl_read(data->fdf, argv[1]);
	mlx_expose_hook(data->win_ptr, expose_hook, data);
	mlx_key_hook(data->win_ptr, press_key, data);
	mlx_mouse_hook(data->win_ptr, press_mouse, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, end_program, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
