/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   net_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:05:54 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/13 19:05:59 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init1(t_var *r, t_net *w)
{
	w->a.x = r->m[w->i][w->j].x * w->ds;
	w->a.y = r->m[w->i][w->j].y * w->ds;
	w->b.x = (r->m[w->i][w->j + 1].x) * w->ds;
	w->b.y = r->m[w->i][w->j].y * w->ds;
	w->c.x = r->m[w->i][w->j].x * w->ds;
	w->c.y = (r->m[w->i + 1][w->j].y) * w->ds;
}

void	init2(t_var *r, t_net *w, int e, int f)
{
	w->a.x = w->a.x + e + r->mv_hor;
	w->a.y = w->a.y - ((r->d->map[w->i][w->j] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	w->b.x = w->b.x + e + r->mv_hor;
	w->b.y = w->b.y - ((r->d->map[w->i][w->j + 1] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	w->c.x = w->c.x + e + r->mv_hor;
	w->c.y = w->c.y - ((r->d->map[w->i + 1][w->j] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	r->color = r->col[w->i][w->j];
	line_draw(w->a, w->b, r);
	line_draw(w->a, w->c, r);
}

void	init3(t_var *r, t_net *w, int e, int f)
{
	w->a.x = w->a.x + e + r->mv_hor;
	w->a.y = w->a.y - ((r->d->map[w->i][w->j] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	w->b.x = w->b.x + e + r->mv_hor;
	w->b.y = w->b.y - ((r->d->map[w->i + 1][w->j] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	r->color = r->col[w->i][w->j];
	line_draw(w->a, w->b, r);
}

void	init4(t_var *r, t_net *w, int e, int f)
{
	w->a.x = w->a.x + e + r->mv_hor;
	w->a.y = w->a.y - ((r->d->map[w->i][w->j] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	w->b.x = w->b.x + e + r->mv_hor;
	w->b.y = w->b.y - ((r->d->map[w->i][w->j + 1] * r->alt) * w->ds)\
			+ f + r->mv_ver;
	r->color = r->col[w->i][w->j];
	line_draw(w->a, w->b, r);
}
