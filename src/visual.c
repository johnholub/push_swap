/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:35:46 by yholub            #+#    #+#             */
/*   Updated: 2018/08/07 14:35:47 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stk *stack)
{
	if (stack == NULL)
	{
		ft_printf("Empty\n");
		return ;
	}
	ft_printf("%i ", stack->val);
	while (stack->next)
	{
		stack = stack->next;
		ft_printf("%i ", stack->val);
	}
	ft_printf("\n");
}

void	visualization(char *buff, t_ps *stu, t_flags *s)
{
	t_stk *a;
	t_stk *b;

	if (s->c == 1)
		ft_printf("Command: %s\n", buff);
	if (s->v == 1)
	{
		a = stu->a;
		b = stu->b;
		ft_printf("Stack a: ");
		print_stack(a);
		ft_printf("Stack b: ");
		print_stack(b);
		ft_printf("\n");
	}
}
