/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:36:24 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:07 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printresult(t_op *op)
{
	if (op != NULL)
	{
		ft_printf("%s\n", op->op);
		while (op->next)
		{
			op = op->next;
			ft_printf("%s\n", op->op);
		}
	}
}

int		main(int argc, char **argv)
{
	t_ps *stu;

	if (check_arg(argv, argc))
	{
		stu = init_struct(argv, argc);
		if (second_valid(stu->a))
		{
			if (is_sort(stu->a))
				exit(1);
			sort_ps(stu);
			optimize_op_num(stu->op);
			printresult(stu->op);
		}
		else
			ft_printf("Error\n");
	}
	else
		ft_printf("Error\n");
	return (0);
}
