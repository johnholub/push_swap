/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:48:32 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:20:06 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	del_last_list(t_ps *stu)
{
	t_cou	*temp;

	if (stu->cou->count == 0)
		return ;
	temp = stu->cou;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

int		sort_rel_mid(int i, t_ps *stu, int mid, t_cou *temp)
{
	if (mid > stu->a->val)
	{
		push_b(stu, 1);
		temp->count++;
	}
	else
	{
		rotate_a(stu, 1);
		if (is_need_sh_up_b(stu->b, INT_MIN))
			rotate_b(stu, 1);
	}
	i++;
	return (i);
}

t_cou	*init_count(void)
{
	t_cou *res;

	res = (t_cou *)malloc(sizeof(t_cou));
	res->count = 0;
	res->bot = 0;
	res->next = 0;
	return (res);
}

void	push_smaller(t_ps *stu)
{
	int		size;
	int		mid;
	int		i;
	t_cou	*temp;

	temp = stu->cou;
	size = find_size(stu->a);
	while (size > 3 && !is_sort(stu->a))
	{
		i = 0;
		mid = find_mid_val(stu->a);
		while (i < size && !is_nessesary(mid, stu->a))
		{
			if (is_need_shift_up(stu->a, mid))
				rev_rot_a(stu, 1);
			else
				i = sort_rel_mid(i, stu, mid, temp);
		}
		temp->next = init_count();
		temp = temp->next;
		size = find_size(stu->a);
	}
	del_last_list(stu);
}

void	sort_ps(t_ps *stu)
{
	push_smaller(stu);
	sort_first_three(stu);
	push_back(stu);
}
