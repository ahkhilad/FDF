/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:00:11 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/15 21:46:04 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	options_menu(t_var *v)
{
	int		col;

	col = 0xff4500;
	mlx_string_put(v->mptr, v->wptr, 1355, 30, col, "----------");
	mlx_string_put(v->mptr, v->wptr, 1350, 39, col, "| OPTIONS |");
	mlx_string_put(v->mptr, v->wptr, 1355, 50, col, "----------");
	mlx_string_put(v->mptr, v->wptr, 1210, 100, col, "[ Mouse Control ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 140, col, "Zoom in");
	mlx_string_put(v->mptr, v->wptr, 1269, 130, col, "|^|");
	mlx_string_put(v->mptr, v->wptr, 1274, 146, col, "||");
	mlx_string_put(v->mptr, v->wptr, 1320, 200, col, "Zoom out");
	mlx_string_put(v->mptr, v->wptr, 1274, 194, col, "||");
	mlx_string_put(v->mptr, v->wptr, 1269, 210, col, "|v|");
}

void	options_menu1(t_var *v)
{
	int		col;

	col = 0xff4500;
	mlx_string_put(v->mptr, v->wptr, 1210, 260, col, "[ Keyboard Control ]");
	mlx_string_put(v->mptr, v->wptr, 1370, 340, col, "Move the projection");
	mlx_string_put(v->mptr, v->wptr, 1210, 340, col, "[ < ]");
	mlx_string_put(v->mptr, v->wptr, 1260, 340, col, "[ v ]");
	mlx_string_put(v->mptr, v->wptr, 1260, 320, col, "[ ^ ]");
	mlx_string_put(v->mptr, v->wptr, 1310, 340, col, "[ > ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 380, col, "Change the projection");
	mlx_string_put(v->mptr, v->wptr, 1210, 380, col, "[ I ][ O ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 420, col, "Increase altitude");
	mlx_string_put(v->mptr, v->wptr, 1260, 420, col, "[ + ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 440, col, "Decrease altitude");
	mlx_string_put(v->mptr, v->wptr, 1260, 440, col, "[ - ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 480, col, "Rotate on X axis");
	mlx_string_put(v->mptr, v->wptr, 1210, 480, col, "[ 8 ][ 2 ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 500, col, "Rotate on Y axis");
	mlx_string_put(v->mptr, v->wptr, 1210, 500, col, "[ 6 ][ 4 ]");
}

void	options_menu2(t_var *v)
{
	int		col;

	col = 0xff4500;
	mlx_string_put(v->mptr, v->wptr, 1320, 540, col, "Change colors");
	mlx_string_put(v->mptr, v->wptr, 1260, 540, col, "[ C ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 560, col, "Change colors backwards");
	mlx_string_put(v->mptr, v->wptr, 1260, 560, col, "[ X ]");
	mlx_string_put(v->mptr, v->wptr, 1320, 580, col, "Default colors");
	mlx_string_put(v->mptr, v->wptr, 1260, 580, col, "[ D ]");
	mlx_string_put(v->mptr, v->wptr, 1360, 650, 0xff0000, "Terminate The \
			Program");
	mlx_string_put(v->mptr, v->wptr, 1242, 640, 0xff0000, "[ Esc ]");
	mlx_string_put(v->mptr, v->wptr, 1242, 665, 0xff0000, "Red Button");
	mlx_string_put(v->mptr, v->wptr, 1242, 840, 0xff0000, "Zoom : x");
	mlx_string_put(v->mptr, v->wptr, 1242, 870, 0xff0000, "X-axis offset :");
	mlx_string_put(v->mptr, v->wptr, 1242, 900, 0xff0000, "Y-axis offset :");
	mlx_string_put(v->mptr, v->wptr, 1325, 840, 0xfcc203, ft_itoa(v->zoom));
	mlx_string_put(v->mptr, v->wptr, 1395, 870, 0xfcc203, ft_itoa(v->mv_hor));
	mlx_string_put(v->mptr, v->wptr, 1395, 900, 0xfcc203, ft_itoa(v->mv_ver));
}

void	var_init(t_var *v)
{
	v->zoom = 1;
	v->mv_ver = 0;
	v->mv_hor = 0;
	v->alt = 0.5;
	v->c_mods = 0;
	v->rot_on_x = 0.05;
	v->rot_on_y = 0.05;
}

void	key_handling(t_var *v)
{
	mlx_put_image_to_window(v->mptr, v->wptr, v->img_ptr, 0, 0);
	mlx_hook(v->wptr, 2, 0, key_press, (void *)v);
	mlx_hook(v->wptr, 4, 0, mouse_press, (void *)v);
	mlx_hook(v->wptr, 17, 0, red_button, (void *)v);
	options_menu(v);
	options_menu1(v);
	options_menu2(v);
	mlx_loop(v->mptr);
}
