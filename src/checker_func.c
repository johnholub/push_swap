/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:17:15 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:18:05 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps	*init_struct(char **mass, int len)
{
	t_ps	*res;
	char	**temp;

	res = (t_ps*)malloc(sizeof(t_ps));
	res->b = NULL;
	res->cou = init_count();
	temp = get_mass(mass, len);
	res->count = mass_len(temp);
	res->a = make_lst(temp);
	res->op = NULL;
	return (res);
}

int		is_cor_inst(char *buff)
{
	if (!ft_strcmp(buff, "ra"))
		return (1);
	else if (!ft_strcmp(buff, "rb"))
		return (1);
	else if (!ft_strcmp(buff, "rr"))
		return (1);
	else if (!ft_strcmp(buff, "rra"))
		return (1);
	else if (!ft_strcmp(buff, "rrb"))
		return (1);
	else if (!ft_strcmp(buff, "rrr"))
		return (1);
	else if (!ft_strcmp(buff, "pa"))
		return (1);
	else if (!ft_strcmp(buff, "pb"))
		return (1);
	else if (!ft_strcmp(buff, "sa"))
		return (1);
	else if (!ft_strcmp(buff, "sb"))
		return (1);
	else if (!ft_strcmp(buff, "ss"))
		return (1);
	return (0);
}
