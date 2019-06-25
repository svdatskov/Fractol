/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:25:19 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:38:19 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_param *param;

	if (argc == 2 && ft_check(argv[1]))
	{
		param = mlx_initial(argv[1]);
		param->number = ft_check(argv[1]);
		if (param->number > 0)
		{
			print_menu(param);
			ft_draw_fractal(param);
			mlx_manipulation(param);
			mlx_loop(param->mlx_ptr);
		}
	}
	else
		ft_error(1);
	return (0);
}
