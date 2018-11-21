/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rel_med.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 10:09:38 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:20:34 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	del_one_and_rep(t_op *op)
{
	t_op *p1;
	t_op *p2;
	t_op *p3;

	p1 = op->next;
	p2 = op->next->next;
	if (op->next->next->next != NULL)
	{
		p3 = op->next->next->next;
		p1->next = p3;
	}
	else
		p1->next = NULL;
	if (p1 != NULL)
		p1->op[ft_strlen(p1->op) - 1] = p1->op[0];
	if (p2 != NULL)
	{
		ft_strdel(&p2->op);
		free(p2);
	}
}

void	find_pre_last_block(t_ps *stu)
{
	t_cou	*res;

	res = stu->cou;
	if (stu->cou->next == NULL)
		return ;
	while (res->next->next)
		res = res->next;
	free(res->next);
	res->next = NULL;
}

int		ft_get_medium(t_ps *stu, int size)
{
	int		*mas;
	int		*temp;
	int		res;

	temp = lst_to_mas(stu->a, size);
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

int		sort_rel_med(t_ps *stu, int h_m)
{
	int		mid;
	int		i;
	int		lim;
	int		bot;
	t_cou	*temp;

	temp = find_last_block(stu->cou);
	bot = 0;
	while (h_m > 3 || bot != 0)
	{
		lim = h_m;
		i = 0;
		temp->next = init_count();
		temp = temp->next;
		mid = ft_get_medium(stu, h_m);
		while (i++ < lim)
		{
			if (mid > stu->a->val)
				h_m = add_to_pb(stu, temp, h_m);
			else
				bot = add_to_ra(stu, bot);
		}
		bot = shiftup_on_n(stu, bot);
	}
	return (h_m);
}
