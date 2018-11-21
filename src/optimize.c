/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:51:19 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:24 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		is_rep_and_del(t_op *op)
{
	if (op->next->next != NULL)
	{
		if (!ft_strcmp(op->next->op, "ra") &&
				!ft_strcmp(op->next->next->op, "rb"))
			return (1);
		if (!ft_strcmp(op->next->op, "rb") &&
				!ft_strcmp(op->next->next->op, "ra"))
			return (1);
		if (!ft_strcmp(op->next->op, "rra") &&
				!ft_strcmp(op->next->next->op, "rrb"))
			return (1);
		if (!ft_strcmp(op->next->op, "rrb") &&
				!ft_strcmp(op->next->next->op, "rra"))
			return (1);
		if (!ft_strcmp(op->next->op, "sa") &&
				!ft_strcmp(op->next->next->op, "sb"))
			return (1);
		if (!ft_strcmp(op->next->op, "sb") &&
				!ft_strcmp(op->next->next->op, "sa"))
			return (1);
	}
	return (0);
}

int		is_del_instuct(t_op *op)
{
	if (op->next->next != NULL)
	{
		if (!ft_strcmp(op->next->op, "ra") &&
				!ft_strcmp(op->next->next->op, "rra"))
			return (1);
		if (!ft_strcmp(op->next->op, "rra") &&
				!ft_strcmp(op->next->next->op, "ra"))
			return (1);
		if (!ft_strcmp(op->next->op, "rb") &&
				!ft_strcmp(op->next->next->op, "rrb"))
			return (1);
		if (!ft_strcmp(op->next->op, "rrb") &&
				!ft_strcmp(op->next->next->op, "rb"))
			return (1);
		if (!ft_strcmp(op->next->op, "pa") &&
				!ft_strcmp(op->next->next->op, "pb"))
			return (1);
		if (!ft_strcmp(op->next->op, "pb") &&
				!ft_strcmp(op->next->next->op, "pa"))
			return (1);
	}
	return (0);
}

int		is_rep(t_op *op)
{
	t_op	*temp;

	temp = op;
	while (temp->next)
	{
		if (is_del_instuct(temp) == 1)
			return (1);
		if (is_rep_and_del(temp) == 1)
			return (1);
		if (is_another_one(temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	optimize_tmp(t_op *temp)
{
	while (temp->next)
	{
		if (is_del_instuct(temp))
		{
			del_two_ops(temp);
			if (temp->next == NULL)
				break ;
		}
		if (is_rep_and_del(temp))
		{
			del_one_and_rep(temp);
			if (temp->next == NULL)
				break ;
		}
		if (is_another_one(temp))
		{
			change_this_com(temp);
			if (temp->next == NULL)
				break ;
		}
		temp = temp->next;
	}
}

void	optimize_op_num(t_op *op)
{
	t_op *temp;

	if (op == NULL)
		return ;
	while (is_rep(op))
	{
		temp = op;
		optimize_tmp(temp);
	}
}
