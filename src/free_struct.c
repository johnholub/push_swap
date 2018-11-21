/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:20:41 by yholub            #+#    #+#             */
/*   Updated: 2018/08/08 14:20:42 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_op(t_op *stack)
{
	t_op *temp;

	if (stack != NULL)
	{
		if (stack->next != NULL)
		{
			while (stack->next->next)
			{
				temp = stack;
				while (temp->next->next)
					temp = temp->next;
				free(temp->next);
				temp->next = NULL;
			}
			free(stack->next);
			stack->next = NULL;
		}
		free(stack);
	}
}

void	free_cou(t_cou *stack)
{
	t_cou *temp;

	if (stack != NULL)
	{
		if (stack->next != NULL)
		{
			while (stack->next->next)
			{
				temp = stack;
				while (temp->next->next)
					temp = temp->next;
				free(temp->next);
				temp->next = NULL;
			}
			free(stack->next);
			stack->next = NULL;
		}
		free(stack);
	}
}

void	free_lst(t_stk *stack)
{
	t_stk *temp;

	if (stack != NULL)
	{
		if (stack->next != NULL)
		{
			while (stack->next->next)
			{
				temp = find_prelast(stack);
				free(temp->next);
				temp->next = NULL;
			}
			free(stack->next);
			stack->next = NULL;
		}
		free(stack);
	}
}

void	free_ps(t_ps *stu)
{
	free_lst(stu->a);
	free_lst(stu->b);
	free_cou(stu->cou);
	free_op(stu->op);
	free(stu);
}
