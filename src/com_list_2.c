/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_list_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:38:50 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:18:34 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rot_a(t_ps *stu, int i)
{
	t_stk	*tmp;
	void	*p1;
	void	*p2;

	if (stu->a == NULL || stu->a->next == NULL)
		return ;
	tmp = find_prelast(stu->a);
	p1 = tmp->next;
	p2 = stu->a;
	stu->a = p1;
	stu->a->next = p2;
	tmp->next = NULL;
	if (i == 1)
		put_op(stu, "rra");
}

void	rev_rot_b(t_ps *stu, int i)
{
	t_stk	*tmp;
	void	*p1;
	void	*p2;

	if (stu->b == NULL || stu->b->next == NULL)
		return ;
	tmp = find_prelast(stu->b);
	p1 = tmp->next;
	p2 = stu->b;
	stu->b = p1;
	stu->b->next = p2;
	tmp->next = NULL;
	if (i == 1)
		put_op(stu, "rrb");
}

void	rev_rot_both(t_ps *stu, int i)
{
	rev_rot_a(stu, 0);
	rev_rot_b(stu, 0);
	if (i == 1)
		put_op(stu, "rrr");
}

void	rotate_a(t_ps *stu, int i)
{
	t_stk	*tmp;
	void	*p1;

	if (stu->a == NULL || stu->a->next == NULL)
		return ;
	tmp = find_last(stu->a);
	p1 = stu->a;
	stu->a = stu->a->next;
	tmp->next = p1;
	tmp = tmp->next;
	tmp->next = NULL;
	if (i == 1)
		put_op(stu, "ra");
}

void	rotate_b(t_ps *stu, int i)
{
	t_stk	*tmp;
	void	*p1;

	if (stu->b == NULL || stu->b->next == NULL)
		return ;
	tmp = find_last(stu->b);
	p1 = stu->b;
	stu->b = stu->b->next;
	tmp->next = p1;
	tmp = tmp->next;
	tmp->next = NULL;
	if (i == 1)
		put_op(stu, "rb");
}
