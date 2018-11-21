/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 09:52:52 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:31 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	del_two_ops(t_op *op)
{
	t_op *p1;
	t_op *p2;
	t_op *p3;

	p1 = op->next;
	p2 = op->next->next;
	if (op->next->next->next != NULL)
	{
		p3 = op->next->next->next;
		op->next = p3;
	}
	else
		op->next = NULL;
	if (p1 != NULL)
	{
		ft_strdel(&p1->op);
		free(p1);
	}
	if (p2 != NULL)
	{
		ft_strdel(&p2->op);
		free(p2);
	}
}

int		is_nessesary(int mid, t_stk *stu)
{
	t_stk	*temp;

	temp = stu;
	if (mid > temp->val)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		if (mid > temp->val)
			return (0);
	}
	return (1);
}

int		is_ssesary(int mid, t_stk *stu)
{
	t_stk	*temp;

	temp = stu;
	if (mid >= temp->val)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		if (mid >= temp->val)
			return (0);
	}
	return (1);
}

void	change_this_com(t_op *op)
{
	t_op *p1;
	t_op *p2;
	t_op *p3;
	t_op *p4;

	p1 = op->next;
	p2 = op->next->next;
	p3 = op->next->next->next;
	if (op->next->next->next->next != NULL)
	{
		p4 = op->next->next->next->next;
		p2->next = p4;
	}
	else
		p2->next = NULL;
	p1->op[0] = 's';
	if (p3 != NULL)
	{
		ft_strdel(&p3->op);
		free(p3);
	}
}

int		is_another_one(t_op *op)
{
	if (op->next->next != NULL && op->next->next->next != NULL)
	{
		if (!ft_strcmp(op->next->op, "ra") &&
				!ft_strcmp(op->next->next->op, "pb")
				&& !ft_strcmp(op->next->next->next->op, "rra"))
			return (1);
		if (!ft_strcmp(op->next->op, "rb") &&
				!ft_strcmp(op->next->next->op, "pa")
				&& !ft_strcmp(op->next->next->next->op, "rrb"))
			return (1);
	}
	return (0);
}
