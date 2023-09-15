/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:30 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:30 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// ========================================================================== //
// Includes
// ========================================================================== //
//local libraries
# include "color.h"
# include "error.h"
# include "../libft/libft.h"
//external libraries
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
# include "mlx.h"
# include "math.h"
# include "X11/X.h"
# include "X11/keysym.h"

// ========================================================================== //
// Structs
// ========================================================================== //
//Image
typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

//Controls
typedef struct s_control
{
	double		zoom;
	double		zout;
	int			color;
	int			shift_x;
	int			shift_y;
	int			x_angle;
	int			y_angle;
	int			z_angle;
}	t_control;

//Positions
typedef struct s_position
{
	int			px;
	int			py;
	int			pz;
	int			rx;
	int			ry;
	int			rz;
	int			ix;
	int			iy;
	int			color;
}	t_position;

//Init
typedef struct s_fdf
{
	t_position	***position;
	t_control	*control;
	int			x;
	int			y;
	int			error;
	int			height;
	int			width;
	int			delta_x;
	int			delta_y;
	int			slope_x;
	int			slope_y;
	int			projection;
}	t_fdf;

//Window struct
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_img		legend;
	t_fdf		*fdf;
}	t_data;

// ========================================================================== //
// Functions
// ========================================================================== //
//main
void		print_points(t_fdf *fdf);
int			expose_hook(t_data *data);
//init
void		init_mlx(t_data *data, char *buffer);
t_control	*init_control(void);
void		reset_control(t_fdf *fdf);
void		check_fdf(t_fdf *fdf);
//draw
void		set_map(t_data *data);
//projection
void		img_pix_put(t_img *img, int y, int x, int color);
double		radian_ang(int angle);
void		projection(t_fdf *fdf);
void		reproject(t_data *data);
//color
int			set_color(t_fdf *fdf, int z);
int			get_color(t_fdf *fdf, t_position *start, t_position *end);
//keys
int			press_key(int keysym, t_data *data);
int			press_mouse(int button, int x, int y, t_data *data);
//read
int			get_width(t_fdf *fdf, char **values, int n_line);
void		lide_value(char	**values, t_fdf *fdf, int y);
void		get_line(t_fdf *fdf, char *buffer);
void		gnl_read(t_fdf *fdf, char *buffer);
int			get_height(char *buffer);
//rotate
void		rotate(t_fdf *fdf);
//legend
void		draw_legend(t_data *data);
void		render_back(t_img *img, int color);
//Free
void		free_all(t_data *data);
int			end_program(t_data *data);
void		print_error(char *error_msg);

#endif
