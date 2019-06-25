/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:24:08 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:35:32 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_choose(t_param *param, t_fr fr)
{
	if (param->number == 1)
		ft_julia(param->data_ptr, param, fr);
	else if (param->number == 2)
		ft_mandelbrot(param->data_ptr, param, fr);
	else if (param->number == 3)
		ft_burningship(param->data_ptr, param, fr);
	else if (param->number == 4)
		ft_per_celtic(param->data_ptr, param, fr);
	else if (param->number == 5)
		ft_cub_man(param->data_ptr, param, fr);
	else if (param->number == 6)
		ft_mandelbrot4(param->data_ptr, param, fr);
	else if (param->number == 7)
		ft_cubic_man(param->data_ptr, param, fr);
	else if (param->number == 8)
		ft_celtic_heart(param->data_ptr, param, fr);
}

void			*draw_pthread(void *parametr)
{
	t_thread	*p;
	t_fr		fr;

	p = (t_thread*)parametr;
	fr.width = IMG_WIDTH;
	fr.height = p->end;
	fr.y = p->start;
	while (fr.y < fr.height)
	{
		fr.x = 0;
		while (fr.x < fr.width)
		{
			ft_choose(p->param, fr);
			fr.x++;
		}
		fr.y++;
	}
	return (p);
}

static void		thread_join(int i, pthread_t *t)
{
	i = 0;
	while (i < THRD)
	{
		pthread_join(t[i], NULL);
		i++;
	}
}

void			ft_draw_fractal(t_param *param)
{
	pthread_t			t[THRD];
	t_thread			p[THRD];
	int					i;
	int					step;

	i = 0;
	step = 0;
	p[0].start = 0;
	p[0].end = 0;
	p[0].param = param;
	while (i < THRD)
	{
		if (i > 0)
			p[i] = p[i - 1];
		p[i].start = step;
		step += HEIGHT / THRD;
		p[i].end = step;
		pthread_create(&t[i], NULL, draw_pthread, &p[i]);
		i++;
	}
	i = 0;
	thread_join(i, t);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
			param->img_ptr, MENU, 0);
}
