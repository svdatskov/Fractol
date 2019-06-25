/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:25:05 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:37:51 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(char *img_data, t_param *param, t_fr fr)
{
	fr.new_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.new_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) < 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.new_re = fr.old_re * fr.old_re - fr.old_im * fr.old_im + param->c_re;
		fr.new_im = 2 * fr.old_re * fr.old_im + param->c_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}

void	ft_burningship(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) < 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.new_re = fabs(fr.old_re * fr.old_re) -
				fr.old_im * fr.old_im + fr.p_re;
		fr.new_im = 2 * fabs(fr.old_re * fr.old_im) + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}

void	ft_mandelbrot(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) <= 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.new_re = fr.old_re * fr.old_re - fr.old_im * fr.old_im + fr.p_re;
		fr.new_im = 2 * fr.old_re * fr.old_im + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}

void	ft_per_celtic(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) <= 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.re_sqr = fr.old_re * fr.old_re;
		fr.im_sqr = fr.old_im * fr.old_im;
		fr.new_re = fabs(fr.re_sqr - fr.im_sqr) + fr.p_re;
		fr.new_im = -2 * fabs(fr.old_re) * fr.old_im + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}

void	ft_cub_man(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) <= 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.re_sqr = fr.old_re * fr.old_re;
		fr.im_sqr = fr.old_im * fr.old_im;
		fr.new_re = -(fr.re_sqr - (fr.im_sqr * 3)) * fr.old_re + fr.p_re;
		fr.new_im = ((fr.re_sqr * 3) - fr.im_sqr) * fr.old_im + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}
