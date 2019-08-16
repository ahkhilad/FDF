/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:51:01 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/13 16:15:31 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		scaling(t_var *s)
{
	s->sc = 0;
	if (s->len <= 1000)
		s->sc = 22;
	else if ((s->len > 1000) && (s->len <= 10000))
		s->sc = 15;
	else if ((s->len > 10000) && (s->len <= 30000))
		s->sc = 10;
	else if ((s->len > 30000) && (s->len <= 100000))
		s->sc = 2;
	else if (s->len > 100000)
		s->sc = 0;
	return (s->sc);
}

void	centring(t_var *r)
{
	t_net	w;
	int		e;
	int		f;

	w.i = 0;
	w.ds = scaling(r) + r->zoom;
	e = IMG_W / 2;
	f = IMG_H / 2;
	while (w.i < r->d->y)
	{
		w.j = 0;
		while (w.j < r->d->x)
		{
			r->m[w.i][w.j].x = w.j - r->d->x / 2;
			r->m[w.i][w.j].y = w.i - r->d->y / 2;
			w.j++;
		}
		w.i++;
	}
	net_creation(r, &w, e, f);
	net_creation1(r, &w, e, f);
	net_creation2(r, &w, e, f);
}

void	net_creation(t_var *r, t_net *w, int e, int f)
{
	w->i = 0;
	while (w->i < r->d->y - 1)
	{
		w->j = 0;
		while (w->j < r->d->x - 1)
		{
			init1(r, w);
			if (r->x_rot == 91 || r->x_rot == 84)
				rotation1(r, w);
			if (r->y_rot == 86 || r->y_rot == 88)
				rotation2(r, w);
			if (r->flag == 34)
			{
				iso_projection(&w->a.x, &w->a.y);
				iso_projection(&w->b.x, &w->b.y);
				iso_projection(&w->c.x, &w->c.y);
			}
			init2(r, w, e, f);
			w->j++;
		}
		w->i++;
	}
}

void	net_creation1(t_var *r, t_net *w, int e, int f)
{
	w->j = r->d->x - 1;
	w->i = -1;
	while (++w->i < r->d->y - 1)
	{
		w->a.x = r->m[w->i][w->j].x * w->ds;
		w->a.y = r->m[w->i][w->j].y * w->ds;
		w->b.x = r->m[w->i][w->j].x * w->ds;
		w->b.y = r->m[w->i + 1][w->j].y * w->ds;
		if (r->x_rot == 91 || r->x_rot == 84)
		{
			x_rotation(&w->a.x, &w->a.y, r);
			x_rotation(&w->b.x, &w->b.y, r);
		}
		if (r->y_rot == 86 || r->y_rot == 88)
		{
			y_rotation(&w->a.x, &w->a.y, r);
			y_rotation(&w->b.x, &w->b.y, r);
		}
		if (r->flag == 34)
		{
			iso_projection(&w->a.x, &w->a.y);
			iso_projection(&w->b.x, &w->b.y);
		}
		init3(r, w, e, f);
	}
}

void	net_creation2(t_var *r, t_net *w, int e, int f)
{
	w->i = r->d->y - 1;
	w->j = -1;
	while (++w->j < r->d->x - 1)
	{
		w->a.x = r->m[w->i][w->j].x * w->ds;
		w->a.y = r->m[w->i][w->j].y * w->ds;
		w->b.x = r->m[w->i][w->j + 1].x * w->ds;
		w->b.y = r->m[w->i][w->j].y * w->ds;
		if (r->x_rot == 91 || r->x_rot == 84)
		{
			x_rotation(&w->a.x, &w->a.y, r);
			x_rotation(&w->b.x, &w->b.y, r);
		}
		if (r->y_rot == 86 || r->y_rot == 88)
		{
			y_rotation(&w->a.x, &w->a.y, r);
			y_rotation(&w->b.x, &w->b.y, r);
		}
		if (r->flag == 34)
		{
			iso_projection(&w->a.x, &w->a.y);
			iso_projection(&w->b.x, &w->b.y);
		}
		init4(r, w, e, f);
	}
}
