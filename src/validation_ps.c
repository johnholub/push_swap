/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:39:52 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:20:42 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		is_uniq(int val, t_stk *stu)
{
	t_stk *tmp;

	tmp = stu;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->val == val)
			return (0);
	}
	return (1);
}

int		second_valid(t_stk *stu)
{
	t_stk	*t_hd;

	if (stu == NULL)
		return (1);
	t_hd = stu;
	while (t_hd->next)
	{
		if (!is_uniq(t_hd->val, t_hd))
			return (0);
		t_hd = t_hd->next;
	}
	return (1);
}

int		check_each(char **temp, int i)
{
	int y;
	int x;

	y = i;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (!ft_isdigit(temp[y][x]) && temp[y][x] != '-')
				return (0);
			if (temp[y][x] == '-' && !ft_isdigit(temp[y][x + 1]))
				return (0);
			if (temp[y][x] == '-' && ft_isdigit(temp[y][x - 1]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	**split_it(char *s)
{
	int		i;
	char	c;
	char	**res;

	i = 0;
	while (s[i])
	{
		if (ft_iswhitespace(s[i]))
		{
			c = s[i];
			break ;
		}
		i++;
	}
	if (i < (int)ft_strlen(s))
		res = ft_strsplit(s, c);
	else
		res = ft_strsplit(s, ' ');
	return (res);
}

int		check_arg(char **s, int len)
{
	char	**temp;

	temp = NULL;
	if (len == 1)
		return (1);
	if (len == 2)
	{
		temp = split_it(s[1]);
		if (check_each(temp, 0))
		{
			free_mass(temp);
			return (1);
		}
	}
	if (len > 2)
	{
		if (check_each(s, 1))
			return (1);
	}
	if (temp != NULL)
		free_mass(temp);
	return (0);
}
