/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:24:33 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:36:14 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_param(t_param *param)
{
	if (ft_strcmp(param->name, "Julia") == 0 ||
	ft_strcmp(param->name, "Cubic_Mandelbar") == 0 ||
	ft_strcmp(param->name, "Perpendicular_Celtic") == 0 ||
	ft_strcmp(param->name, "Cubic_Mandelbrot") == 0 ||
	ft_strcmp(param->name, "Mandelbrot_4_Order") == 0)
	{
		param->move_x = 0;
		param->move_y = 0;
		param->zoom = 0.7;
	}
	else if (ft_strcmp(param->name, "Mandelbrot") == 0
	|| ft_strcmp(param->name, "Celtic_Heart") == 0)
	{
		param->move_x = -0.5;
		param->move_y = 0;
		param->zoom = 1;
	}
	else if (ft_strcmp(param->name, "Burningship") == 0)
	{
		param->move_x = -0.4;
		param->move_y = -0.6;
		param->zoom = 0.7;
	}
	param->max_iterations = 36;
}

t_param		*mlx_initial(char *name)
{
	t_param *param;

	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(2);
	else
	{
		param->bpp = 32;
		param->size_line = IMG_WIDTH * 4;
		param->endian = 0;
		param->mlx_ptr = mlx_init();
		param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, name);
		param->img_ptr = mlx_new_image(param->mlx_ptr, IMG_WIDTH, HEIGHT);
		param->data_ptr = mlx_get_data_addr(param->img_ptr,
				&param->bpp, &param->size_line, &param->endian);
		param->name = name;
		param->c_re = -0.2;
		param->c_im = -0.7;
		param->locker = -1;
		set_param(param);
	}
	return (param);
}
