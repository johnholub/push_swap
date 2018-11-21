/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:16:12 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:21:43 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*lst_to_mas(t_stk *lst, int size)
{
	int		*res;
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	res = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		res[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

int		min_value(int *mass, int size)
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

int		*fill_sort(int *mas, int size)
{
	int i;
	int *res;

	res = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = min_value(mas, size);
		i++;
	}
	return (res);
}

int		mid_to_b(t_ps *stu, int size)
{
	int		*mas;
	int		*temp;
	int		res;

	temp = lst_to_mas(stu->b, size);
	mas = fill_sort(temp, size);
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

t_cou	*find_last_block(t_cou *lst)
{
	t_cou *res;

	res = lst;
	while (res->next)
		res = res->next;
	return (res);
}
