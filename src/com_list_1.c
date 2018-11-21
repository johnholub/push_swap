/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_list_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:38:45 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:18:18 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_ps *stu, int i)
{
	t_stk	*tm_hd;
	void	*p1;

	tm_hd = stu->a;
	if (stu->a == NULL || stu->a->next == NULL)
		return ;
	else
	{
		tm_hd = tm_hd->next;
		p1 = tm_hd->next;
		stu->a->next = p1;
		tm_hd->next = stu->a;
	}
	stu->a = tm_hd;
	if (i == 1)
		put_op(stu, "sa");
}

void	swap_b(t_ps *stu, int i)
{
	t_stk	*tm_hd;
	void	*p1;

	tm_hd = stu->b;
	if (stu->b == NULL || stu->b->next == NULL)
		return ;
	else
	{
		tm_hd = tm_hd->next;
		p1 = tm_hd->next;
		stu->b->next = p1;
		tm_hd->next = stu->b;
	}
	stu->b = tm_hd;
	if (i == 1)
		put_op(stu, "sb");
}

void	swap_both(t_ps *stu, int i)
{
	swap_a(stu, 0);
	swap_b(stu, 0);
	if (i == 1)
		put_op(stu, "ss");
}

void	push_a(t_ps *stu, int i)
{
	void	*p1;
	void	*p2;

	if (stu->b == NULL)
		return ;
	else if (stu->a == NULL)
	{
		stu->a = stu->b;
		if (stu->b->next)
			stu->b = stu->b->next;
		else
			stu->b = NULL;
		stu->a->next = NULL;
	}
	else
	{
		p1 = stu->b;
		p2 = stu->a;
		stu->b = stu->b->next;
		stu->a = p1;
		stu->a->next = p2;
	}
	if (i == 1)
		put_op(stu, "pa");
}

void	push_b(t_ps *stu, int i)
{
	void	*p1;
	void	*p2;

	if (stu->a == NULL)
		return ;
	else if (stu->b == NULL)
	{
		stu->b = stu->a;
		if (stu->a->next)
			stu->a = stu->a->next;
		else
			stu->a = NULL;
		stu->b->next = NULL;
	}
	else
	{
		p1 = stu->a;
		p2 = stu->b;
		stu->a = stu->a->next;
		stu->b = p1;
		stu->b->next = p2;
	}
	if (i == 1)
		put_op(stu, "pb");
}
