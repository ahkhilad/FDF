/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:11:24 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/15 21:46:09 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_open_file(char *file, t_var *r)
{
	int		fd;
	int		**tab;
	char	tmp[1];

	fd = open(file, O_RDONLY);
	if (read(fd, tmp, 0) < 0)
		return (NULL);
	tab = ft_read_map(fd, r);
	return (tab);
}

void	allocations(t_var *my, t_read_var *v)
{
	my->d->y = v->size;
	my->d->map = (int**)malloc(sizeof(int *) * my->d->y);
	my->col = (int**)malloc(sizeof(int *) * my->d->y);
	my->m = (t_pos**)malloc(sizeof(t_pos*) * my->d->y);
	my->d->ret = ft_int_table(v->lines, my, ft_strlen(v->line));
}

int		**ft_read_map(int fd, t_var *my)
{
	t_read_var	v;

	my->d->x = 0;
	v.line = ft_strnew(0);
	while ((v.rd = read(fd, v.buff, BUFF_SIZE)) > 0)
	{
		v.buff[v.rd] = '\0';
		v.tmp = v.line;
		v.line = ft_strjoin(v.line, v.buff);
		free(v.tmp);
	}
	v.tmp = v.line;
	v.lines = ft_strsplit(v.line, '\n');
	free(v.tmp);
	v.size = 0;
	while (v.lines[v.size] != NULL)
		v.size++;
	if (v.size <= 1)
	{
		ft_putendl("Error ! Please try again with a valid file");
		exit(0);
	}
	allocations(my, &v);
	ft_tab_del(v.lines);
	return (my->d->ret);
}

void	loops(t_var *my, int i, char **tab)
{
	int		k;

	k = 0;
	my->d->map[i] = malloc(sizeof(int) * my->d->x);
	my->col[i] = malloc(sizeof(int) * my->d->x);
	my->m[i] = malloc(sizeof(t_pos) * my->d->x);
	while (k < my->d->x)
	{
		my->d->map[i][k] = ft_atoi(tab[k]);
		my->col[i][k] = special_atoi_base(tab[k]);
		if (my->col[i][k] == 0)
			my->col[i][k] = 0x16ff07;
		k++;
	}
}

int		**ft_int_table(char **line, t_var *my, int len)
{
	char		**tab;
	int			i;
	int			j;
	static int	u = 0;

	i = -1;
	while (line[++i])
	{
		tab = ft_strsplit(line[i], ' ');
		j = 0;
		while (tab[j])
			j++;
		if (u == 0)
		{
			my->d->x = j;
			u = 2;
		}
		if (j < my->d->x)
			return (NULL);
		loops(my, i, tab);
	}
	my->len = len;
	centring(my);
	ft_tab_del(tab);
	return (my->d->map);
}
