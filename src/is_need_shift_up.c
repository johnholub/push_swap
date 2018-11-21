/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_need_shift_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:43:48 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:18:55 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		is_need_sh_up_b(t_stk *lst, int med)
{
	t_stk *temp;

	if (lst && lst->next)
	{
		temp = find_last(lst);
		if (temp->val > med && temp->val > lst->val)
			return (1);
	}
	return (0);
}

int		is_need_shift_up(t_stk *lst, int med)
{
	t_stk *temp;

	if (lst && lst->next)
	{
		temp = find_last(lst);
		if (temp->val < med && temp->val < lst->val)
			return (1);
	}
	return (0);
}
