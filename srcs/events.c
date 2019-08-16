/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:09:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/15 21:46:16 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	events1(t_var *r, int keycode)
{
	if (keycode == 53)
	{
		ft_del_int_tab(r);
		free(r->d);
		mlx_destroy_image(r->mptr, r->img_ptr);
		mlx_clear_window(r->mptr, r->wptr);
		mlx_destroy_window(r->mptr, r->wptr);
		exit(0);
	}
	if (keycode == 34)
		r->flag = 34;
	if (keycode == 31)
		r->flag = 31;
	if (keycode == 125)
		r->mv_ver += 3;
	if (keycode == 126)
		r->mv_ver -= 3;
	if (keycode == 124)
		r->mv_hor += 3;
	if (keycode == 123)
		r->mv_hor -= 3;
}

void	events2(t_var *r, int keycode)
{
	if (keycode == 69)
		r->alt += 0.08;
	if (keycode == 78)
		r->alt -= 0.08;
	if (keycode == 8)
		r->c_mods += 1000;
	if (keycode == 7)
		r->c_mods -= 1000;
	if (keycode == 2)
		r->c_mods = 0;
	if (keycode == 91)
	{
		r->x_rot = 91;
		r->rot_on_x += 0.05;
	}
}

void	ft_tab_del(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_del_int_tab(t_var *r)
{
	int		i;

	i = 0;
	while (i < r->d->y)
	{
		free(r->d->map[i]);
		free(r->col[i]);
		free(r->m[i]);
		i++;
	}
	free(r->d->map);
	free(r->col);
	free(r->m);
}
