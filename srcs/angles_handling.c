/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:11:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/13 16:12:35 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(int *x, int *y)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599);
}

void	x_rotation(int *new_x, int *new_y, t_var *r)
{
	int		curr_x;
	int		curr_y;

	curr_x = *new_x;
	curr_y = *new_y;
	*new_x = (1 * curr_x);
	*new_y = (cos(r->rot_on_x) * curr_y);
}

void	y_rotation(int *new_x, int *new_y, t_var *r)
{
	int		curr_x;
	int		curr_y;

	curr_x = *new_x;
	curr_y = *new_y;
	*new_x = (cos(r->rot_on_y) * curr_x);
	*new_y = (1 * curr_y);
}

void	rotation1(t_var *r, t_net *w)
{
	x_rotation(&w->a.x, &w->a.y, r);
	x_rotation(&w->b.x, &w->b.y, r);
	x_rotation(&w->c.x, &w->c.y, r);
}

void	rotation2(t_var *r, t_net *w)
{
	y_rotation(&w->a.x, &w->a.y, r);
	y_rotation(&w->b.x, &w->b.y, r);
	y_rotation(&w->c.x, &w->c.y, r);
}
