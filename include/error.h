/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoda-lu <leoda-lu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:28 by leoda-lu          #+#    #+#             */
/*   Updated: 2023/09/13 15:39:28 by leoda-lu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define USG_ERROR "USAGE: ./fdf <file_name>.\n"
# define MLX_ERROR "\033[1;31mERROR:\033[1;0m Could not start minilibx.\n"
# define WIN_ERROR "\033[1;31mERROR:\033[1;0m Could not start window.\n"
# define GNL_ERROR "\033[1;31mERROR:\033[1;0m Error while reading from file.\n"
# define MLC_ERROR "\033[1;31mERROR:\033[1;0m Error while allocating memory.\n"
# define IMG_ERROR "\033[1;31mERROR:\033[1;0m Error while creating image.\n"
# define OPN_ERROR "\033[1;31mERROR:\033[1;0m Could not open file.\n"
# define MAP_ERROR "\033[1;31mERROR:\033[1;0m Invalid map.\n"

#endif
