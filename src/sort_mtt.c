/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mtt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:05:55 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:57 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	put_op(t_ps *stu, char *str)
{
	t_op	*temp;

	temp = stu->op;
	if (stu->op == NULL)
	{
		stu->op = (t_op *)malloc(sizeof(t_op));
		stu->op->op = ft_strdup(str);
		stu->op->next = NULL;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = (t_op *)malloc(sizeof(t_op));
		temp = temp->next;
		temp->op = ft_strdup(str);
		temp->next = NULL;
	}
}

void	accept_sol(int i, t_ps *stu)
{
	if (i == 1)
	{
		rotate_a(stu, 1);
		swap_a(stu, 1);
		rev_rot_a(stu, 1);
	}
	else if (i == 2)
		swap_a(stu, 1);
	else if (i == 3)
	{
		rotate_a(stu, 1);
		swap_a(stu, 1);
		rev_rot_a(stu, 1);
		swap_a(stu, 1);
	}
	else if (i == 4)
	{
		swap_a(stu, 1);
		rotate_a(stu, 1);
		swap_a(stu, 1);
		rev_rot_a(stu, 1);
		swap_a(stu, 1);
	}
}

int		sort_three(t_ps *stu)
{
	int a;
	int b;
	int c;

	a = stu->a->val;
	b = stu->a->next->val;
	c = stu->a->next->next->val;
	if (a < b && b > c && a < c)
		accept_sol(1, stu);
	else if (a > b && b < c && a < c)
		accept_sol(2, stu);
	else if (a < b && b > c && a > c)
		accept_sol(3, stu);
	else if (a > b && b > c && a > c)
		accept_sol(4, stu);
	else if (a > b && b < c && a > c)
	{
		swap_a(stu, 1);
		rotate_a(stu, 1);
		swap_a(stu, 1);
		rev_rot_a(stu, 1);
	}
	return (0);
}

int		sort_mr_th_tr(t_ps *stu, int h_m)
{
	if (h_m == 1)
		return (0);
	else if (h_m == 2)
	{
		if (is_sort(stu->a))
			return (0);
		else
		{
			swap_a(stu, 1);
			return (0);
		}
	}
	else
	{
		if (is_sort(stu->a))
			return (0);
		else
			sort_three(stu);
	}
	return (0);
}
