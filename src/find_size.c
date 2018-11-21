/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 12:18:41 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:18:47 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		find_size(t_stk *lst)
{
	int		res;
	t_stk	*tmp;

	if (lst == NULL)
		return (0);
	tmp = lst;
	res = 1;
	while (tmp->next)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

int		*lst_to_mass(t_stk *lst)
{
	int		*res;
	t_stk	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = lst;
	size = find_size(lst);
	res = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		res[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

int		min_val(int *mass, int size)
{
	int i;
	int val;
	int	rem;

	i = 0;
	rem = 0;
	val = INT_MAX;
	while (i < size)
	{
		if (val > mass[i])
		{
			val = mass[i];
			rem = i;
		}
		i++;
	}
	mass[rem] = INT_MAX;
	return (val);
}

int		*fill_sorted(t_stk *lst, int *mas)
{
	int i;
	int size;
	int *res;

	size = find_size(lst);
	res = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = min_val(mas, size);
		i++;
	}
	return (res);
}

int		find_mid_val(t_stk *lst)
{
	int		*mas;
	int		*temp;
	int		size;
	int		res;

	size = find_size(lst);
	temp = lst_to_mass(lst);
	mas = fill_sorted(lst, temp);
	free(temp);
	if (size == 2)
		res = 1;
	else if (size % 2 == 0)
		res = size / 2;
	else
		res = (size - 1) / 2;
	res = mas[res];
	free(mas);
	return (res);
}
