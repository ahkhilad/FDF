/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:49:00 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/15 21:45:58 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		red_button(void *p)
{
	t_var	*r;

	r = (t_var *)p;
	ft_del_int_tab(r);
	free(r->d);
	mlx_destroy_image(r->mptr, r->img_ptr);
	mlx_clear_window(r->mptr, r->wptr);
	mlx_destroy_window(r->mptr, r->wptr);
	exit(0);
}

int		key_press(int keycode, void *p)
{
	t_var *r;

	r = (t_var *)p;
	events1(r, keycode);
	events2(r, keycode);
	if (keycode == 84)
	{
		r->x_rot = 84;
		r->rot_on_x -= 0.05;
	}
	if (keycode == 86)
	{
		r->y_rot = 86;
		r->rot_on_y += 0.05;
	}
	if (keycode == 88)
	{
		r->y_rot = 88;
		r->rot_on_y -= 0.05;
	}
	reload_image(r);
	return (0);
}

void	reload_image(t_var *r)
{
	t_img	g;

	mlx_clear_window(r->mptr, r->wptr);
	mlx_destroy_image(r->mptr, r->img_ptr);
	r->img_ptr = mlx_new_image(r->mptr, IMG_W, IMG_H);
	r->rt = (int *)mlx_get_data_addr(r->img_ptr, &g.bpp, &g.size, &g.en);
	centring(r);
	mlx_put_image_to_window(r->mptr, r->wptr, r->img_ptr, 0, 0);
	options_menu(r);
	options_menu1(r);
	options_menu2(r);
}

int		mouse_press(int button, int x, int y, void *p)
{
	t_var	*r;

	x = 0;
	y = 0;
	r = (t_var *)p;
	if (button == 4)
		r->zoom += 2;
	if (button == 5)
	{
		if (r->sc == 2)
			if (r->zoom == 0)
				return (0);
		if (r->sc == 0)
			if (r->zoom == 1)
				return (0);
		if (r->zoom == -14)
			return (0);
		r->zoom -= 1;
	}
	reload_image(r);
	return (0);
}

int		main(int argc, char **argv)
{
	t_var	v;
	int		**map;

	var_init(&v);
	if (argc != 2)
	{
		ft_putendl("usage: fdf target file ex: ./fdf map.fdf");
		exit(0);
	}
	v.mptr = mlx_init();
	v.wptr = mlx_new_window(v.mptr, WIDTH, HEIGHT, argv[1]);
	v.img_ptr = mlx_new_image(v.mptr, IMG_W, IMG_H);
	v.rt = (int *)mlx_get_data_addr(v.img_ptr, &v.g->bpp, &v.g->size, &v.g->en);
	v.d = malloc(sizeof(t_data));
	if (!(map = ft_open_file(argv[1], &v)))
	{
		ft_putendl("Sorry ! invalid file, try again with a valid file");
		free(v.d);
		exit(0);
	}
	key_handling(&v);
	return (0);
}
