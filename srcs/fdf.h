/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:54:06 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/15 21:41:07 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 100000
# define WIDTH 1600
# define HEIGHT 1000

# define IMG_W 1200
# define IMG_H 1000

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef	struct	s_data
{
	int			**map;
	int			y;
	int			x;
	int			**ret;
}				t_data;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_img
{
	int			bpp;
	int			size;
	int			en;
}				t_img;

typedef struct	s_var
{
	void		*mptr;
	void		*wptr;
	void		*img_ptr;
	int			*rt;
	t_img		*g;
	t_data		*d;
	t_pos		**m;
	int			flag;
	int			len;
	int			**col;
	int			color;
	int			zoom;
	int			sc;
	int			mv_ver;
	int			mv_hor;
	float		alt;
	float		rot_on_x;
	float		rot_on_y;
	int			x_rot;
	int			y_rot;
	int			c_mods;
	int			i;
}				t_var;

typedef	struct	s_axis
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_axis;

typedef struct	s_points
{
	int			dx;
	int			dy;
	int			p;
	int			sx;
	int			sy;
}				t_points;

typedef struct	s_cor
{
	int			x;
	int			y;
}				t_cor;

typedef struct	s_net
{
	int			i;
	int			j;
	int			ds;
	t_cor		a;
	t_cor		b;
	t_cor		c;
}				t_net;

typedef struct	s_base
{
	int			i;
	int			p;
	int			rt;
	int			n;
	int			somme;
}				t_base;

typedef struct	s_read_var
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	char		*line;
	int			rd;
	char		**lines;
	int			size;
}				t_read_var;

void			events1(t_var *r, int keycode);
void			events2(t_var *r, int keycode);
void			ft_tab_del(char **str);
void			ft_del_int_tab(t_var *r);
int				mouse_press(int button, int x, int y, void *p);
int				key_press(int keycode, void *p);
int				red_button(void *p);
void			var_init(t_var *v);
void			key_handling(t_var *v);
int				**ft_open_file(char *file, t_var *r);
void			allocations(t_var *my, t_read_var *v);
int				**ft_read_map(int fd, t_var *h);
int				**ft_int_table(char **line, t_var *t, int len);
void			ft_tab_del(char **str);
void			line_draw(t_cor a, t_cor b, t_var *x);
void			first_case(t_cor *a, t_cor *b, t_points *my, t_var *x);
void			second_case(t_cor *a, t_cor *b, t_points *my, t_var *x);
void			centring(t_var *r);
void			net_creation(t_var *r, t_net *w, int e, int f);
void			net_creation1(t_var *r, t_net *w, int e, int f);
void			net_creation2(t_var *r, t_net *w, int e, int f);
void			iso_projection(int *x, int *y);
int				scaling(t_var *s);
void			reload_image(t_var *r);
int				special_atoi_base(char *str);
void			converting_base(char *str, t_base *v);
void			x_rotation(int *new_x, int *new_y, t_var *r);
void			y_rotation(int *new_x, int *new_y, t_var *r);
void			rotation1(t_var *r, t_net *w);
void			rotation2(t_var *r, t_net *w);
void			options_menu(t_var *v);
void			options_menu1(t_var *v);
void			options_menu2(t_var *v);
void			init1(t_var *r, t_net *w);
void			init2(t_var *r, t_net *w, int e, int f);
void			init3(t_var *r, t_net *w, int e, int f);
void			init4(t_var *r, t_net *w, int e, int f);

#endif
