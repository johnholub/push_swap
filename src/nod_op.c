/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nod_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:39:37 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:19:14 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*cr_newnode(char *str)
{
	t_stk	*res;

	if (ft_atoi_x(str) > INT_MAX || ft_atoi_x(str) < INT_MIN)
	{
		ft_printf("Error\n");
		exit(1);
	}
	res = (t_stk *)malloc(sizeof(t_stk));
	res->val = ft_atoi(str);
	res->next = 0;
	return (res);
}

t_stk	*find_prelast(t_stk *lst)
{
	t_stk *res;

	if (lst == NULL)
		return (NULL);
	res = lst;
	while (res->next->next)
		res = res->next;
	return (res);
}

t_stk	*find_last(t_stk *lst)
{
	t_stk *res;

	if (lst == NULL)
		return (NULL);
	res = lst;
	while (res->next)
		res = res->next;
	return (res);
}

t_stk	*make_lst(char **mass)
{
	t_stk	*lst;
	t_stk	*tmp;
	int		i;

	i = 0;
	if (mass != NULL)
	{
		lst = cr_newnode(mass[i]);
		tmp = lst;
		i++;
		while (mass[i])
		{
			lst->next = cr_newnode(mass[i]);
			lst = lst->next;
			i++;
		}
		lst = tmp;
		free_mass(mass);
	}
	else
		lst = NULL;
	return (lst);
}

void	rotate_both(t_ps *stu, int i)
{
	rotate_a(stu, 0);
	rotate_b(stu, 0);
	if (i == 1)
		put_op(stu, "rr");
}
