/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:24:57 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:37:32 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_menu(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 70, 0xF0E68C, "ZOOM: MOUSE WHEEL");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 130, 0xFFDAB9, "Move X: 'A'/'D' Buttons");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 160, 0xFFDAB9, "Move Y: 'W'/ S' Buttons");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 360, 0xFFDAB9, "LOCKER: 'L' BUTTON");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 220, 0xFFE4B5, "ITERATION+ : 'E' BUTTON");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 250, 0xFFE4B5, "ITERATION- : 'Q' BUTTON");
	mlx_string_put(param->mlx_ptr, param->win_ptr,
			5, 300, 0xFF6347, "DEFAULT: 0 Button");
	if (param->locker == -1 && param->number == 1)
		mlx_string_put(param->mlx_ptr, param->win_ptr,
				5, 390, 0x008000, "LOCKER: OFF");
	else if (param->locker == 1 && param->number == 1)
		mlx_string_put(param->mlx_ptr, param->win_ptr,
				5, 390, 0x8B0000, "LOCKER: ON");
}
