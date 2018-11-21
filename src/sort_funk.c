/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:39:57 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:49 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		add_to_pb(t_ps *stu, t_cou *temp, int h_m)
{
	push_b(stu, 1);
	temp->count++;
	h_m--;
	return (h_m);
}

int		add_to_ra(t_ps *stu, int bot)
{
	rotate_a(stu, 1);
	bot++;
	return (bot);
}

int		shiftup_on_n(t_ps *stu, int bot)
{
	int rr;

	if (bot == 0)
		return (0);
	if (find_size(stu->b) - bot < bot)
	{
		rr = find_size(stu->b) - bot;
		while (rr != 0)
		{
			rotate_a(stu, 1);
			rr--;
		}
	}
	else
		while (bot != 0)
		{
			rev_rot_a(stu, 1);
			bot--;
		}
	return (0);
}

void	equal_three(t_ps *lst)
{
	int a;
	int b;
	int c;

	a = lst->a->val;
	b = lst->a->next->val;
	c = lst->a->next->next->val;
	if (a > b && b > c && a > c)
	{
		rotate_a(lst, 1);
		swap_a(lst, 1);
	}
	else if (a < b && b > c && a < c)
	{
		swap_a(lst, 1);
		rotate_a(lst, 1);
	}
	else if (a > b && b < c && a < c)
		swap_a(lst, 1);
	else if (a > b && b < c && a > c)
		rotate_a(lst, 1);
	else if (a < b && b > c && a > c)
		rev_rot_a(lst, 1);
}

void	sort_first_three(t_ps *stu)
{
	if (is_sort(stu->a))
		return ;
	else if (find_size(stu->a) == 1)
		return ;
	else if (find_size(stu->a) == 2)
	{
		if (stu->a->val > stu->a->next->val)
			swap_a(stu, 1);
		else
			return ;
	}
	else if (find_size(stu->a) == 3)
		equal_three(stu);
	else
		return ;
}
