/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:25:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/13 14:52:55 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_filler(t_var *v, int x, int y)
{
	if (x >= IMG_W || IMG_H <= y || x < 0 || y < 0)
		return ;
	v->i = x + IMG_W * y;
	if (v->i < IMG_W * IMG_W)
	{
		if (v->c_mods == 0)
			v->rt[v->i] = v->color;
		else
			v->rt[v->i] = v->color * v->c_mods;
	}
}

void	line_draw(t_cor a, t_cor b, t_var *x)
{
	t_points	my;
	float		m;

	my.dx = abs(a.x - b.x);
	my.dy = abs(a.y - b.y);
	my.sx = a.x < b.x ? 1 : -1;
	my.sy = a.y < b.y ? 1 : -1;
	m = (float)my.dy / my.dx;
	if (m <= 1 && m >= -1)
		first_case(&a, &b, &my, x);
	else
		second_case(&a, &b, &my, x);
}

void	first_case(t_cor *a, t_cor *b, t_points *my, t_var *x)
{
	my->p = 2 * my->dy - my->dx;
	while (1)
	{
		if (a->x == b->x && a->y == b->y)
			break ;
		if (my->p < 0)
		{
			a->x += my->sx;
			my->p = my->p + 2 * my->dy;
			pixel_filler(x, a->x, a->y);
		}
		else
		{
			a->x += my->sx;
			a->y += my->sy;
			my->p = my->p + 2 * my->dy - 2 * my->dx;
			pixel_filler(x, a->x, a->y);
		}
	}
}

void	second_case(t_cor *a, t_cor *b, t_points *my, t_var *x)
{
	my->p = 2 * my->dx - my->dy;
	while (1)
	{
		if (a->x == b->x && a->y == b->y)
			break ;
		if (my->p < 0)
		{
			a->y += my->sy;
			my->p = my->p + 2 * my->dx;
			pixel_filler(x, a->x, a->y);
		}
		else
		{
			a->y += my->sy;
			a->x += my->sx;
			my->p = my->p + 2 * my->dx - 2 * my->dy;
			pixel_filler(x, a->x, a->y);
		}
	}
}
