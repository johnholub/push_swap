/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:10:48 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:39 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		sort_for_mid(t_ps *stu, int mid, t_cou *temp, int h_m)
{
	if (is_need_sh_up_b(stu->b, mid))
		rev_rot_b(stu, 1);
	else if (mid < stu->b->val)
	{
		push_a(stu, 1);
		temp->count--;
		h_m++;
	}
	else
	{
		rotate_b(stu, 1);
		temp->count--;
		temp->bot++;
	}
	return (h_m);
}

void	get_bot_val(t_ps *stu, t_cou *temp)
{
	int rr;

	if (find_size(stu->b) - temp->bot < temp->bot)
	{
		rr = find_size(stu->b) - temp->bot;
		while (rr != 0)
		{
			rotate_b(stu, 1);
			rr--;
		}
		temp->count = temp->bot;
		temp->bot = 0;
	}
	else
		while (temp->bot != 0)
		{
			rev_rot_b(stu, 1);
			temp->bot--;
			temp->count++;
		}
}

int		push_bigger_a(t_ps *stu, int h_m)
{
	t_cou	*temp;
	int		mid;

	temp = find_last_block(stu->cou);
	if (temp->bot != 0 && temp->count == 0)
		get_bot_val(stu, temp);
	if (temp->count <= 3)
		while (temp->count != 0)
		{
			push_a(stu, 1);
			temp->count--;
			h_m++;
		}
	else
	{
		mid = mid_to_b(stu, temp->count);
		while (temp->count != 0)
			if (!is_ssesary(mid, stu->b))
				h_m = sort_for_mid(stu, mid, temp, h_m);
	}
	if (temp->bot == 0 && temp->count == 0)
		find_pre_last_block(stu);
	return (h_m);
}

void	push_back(t_ps *stu)
{
	int h_m;

	h_m = 0;
	while (stu->b)
	{
		h_m = push_bigger_a(stu, h_m);
		while (h_m != 0)
		{
			if (is_sort(stu->a))
				h_m = 0;
			else if (h_m <= 3)
				h_m = sort_mr_th_tr(stu, h_m);
			else
				h_m = sort_rel_med(stu, h_m);
		}
	}
}
