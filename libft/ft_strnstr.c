/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:51:10 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/08/15 20:44:35 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*find;

	i = 0;
	find = (char *)needle;
	if (!str && !find)
		return (0);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == find[j] && find[j]) && i + j < len)
			j++;
		if (!find[j])
			return ((char *)str + i);
		i++;
	}
	return (0);
}
