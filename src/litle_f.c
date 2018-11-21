/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litle_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 13:02:18 by yholub            #+#    #+#             */
/*   Updated: 2018/07/17 13:02:19 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		mass_len(char **mass)
{
	int		len;

	len = 0;
	if (mass == NULL)
		return (0);
	while (mass[len])
		len++;
	return (len);
}

char	**copy_mass(char **src, int len)
{
	int		y;
	int		x;
	char	**dst;

	dst = (char **)malloc(sizeof(char*) * len);
	y = 1;
	x = 0;
	while (src[y])
	{
		dst[x] = ft_strdup(src[y]);
		y++;
		x++;
	}
	dst[x] = 0;
	return (dst);
}

char	**get_mass(char **mass, int len)
{
	char **res;

	if (len == 2)
		res = ft_strsplit(mass[1], ' ');
	else if (len > 2)
		res = copy_mass(mass, len);
	else
		res = NULL;
	return (res);
}

void	free_mass(char **temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		ft_strdel(&temp[i]);
		i++;
	}
	free(temp);
}

int		is_sort(t_stk *lst)
{
	t_stk	*tmp;
	int		cur;

	if (lst == NULL)
		return (1);
	tmp = lst;
	cur = tmp->val;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (cur > tmp->val)
			return (0);
		cur = tmp->val;
	}
	return (1);
}
