/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:36:14 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:36:00 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		key_release(int keycode, void *param)
{
	if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
		ft_move(keycode, param);
	if (keycode == 29)
		ft_base(keycode, param);
	if (keycode == 37)
		ft_locker(param);
	if (keycode == 53)
		exit(0);
	if (keycode == 12 || keycode == 14)
		ft_change_it(keycode, param);
	return (0);
}

static int		mouse_press(int button, int x, int y, t_param *param)
{
	if (button == 4 || button == 5)
	{
		ft_zoom(button, x, y, param);
	}
	return (0);
}

static int		mouse_move(int x, int y, void *param)
{
	x = x - 250;
	if (x > 0 && x <= 1100 && y > 0 && y <= 800)
		ft_move_mouse(x, y, param);
	return (0);
}

static int		ft_exit(void *param)
{
	(void)param;
	exit(0);
}

void			mlx_manipulation(t_param *param)
{
	mlx_hook(param->win_ptr, 17, 0, ft_exit, (void *)0);
	mlx_hook(param->win_ptr, 2, 0, key_release, (void *)param);
	mlx_hook(param->win_ptr, 4, 0, mouse_press, (void *)param);
	if (param->number == 1)
	{
		mlx_hook(param->win_ptr, 6, 0, mouse_move, (void *)param);
	}
}
