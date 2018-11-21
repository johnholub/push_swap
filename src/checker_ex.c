/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:29:05 by yholub            #+#    #+#             */
/*   Updated: 2018/08/07 13:29:06 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*check_notrash(char *str, t_ps *stu)
{
	char	*tmp;
	char	*t_s;
	t_stk	*t_l;
	int		i;
	int		j;

	t_l = find_last(stu->a);
	if (ft_atoi(str) == t_l->val && ft_isdigit(str[0]))
	{
		t_s = ft_itoa(t_l->val);
		i = (int)ft_strlen(t_s);
		tmp = (char *)malloc(sizeof(ft_strlen(str) - ft_strlen(t_s)) + 1);
		j = 0;
		while (str[i])
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
		tmp[j] = '\0';
		ft_strdel(&t_s);
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}

void	accept_fol_inst(char *buff, t_ps *stu)
{
	if (!ft_strcmp(buff, "ra"))
		rotate_a(stu, 0);
	else if (!ft_strcmp(buff, "rb"))
		rotate_b(stu, 0);
	else if (!ft_strcmp(buff, "rr"))
		rotate_both(stu, 0);
	else if (!ft_strcmp(buff, "rra"))
		rev_rot_a(stu, 0);
	else if (!ft_strcmp(buff, "rrb"))
		rev_rot_b(stu, 0);
	else if (!ft_strcmp(buff, "rrr"))
		rev_rot_both(stu, 0);
	else if (!ft_strcmp(buff, "pa"))
		push_a(stu, 0);
	else if (!ft_strcmp(buff, "pb"))
		push_b(stu, 0);
	else if (!ft_strcmp(buff, "sa"))
		swap_a(stu, 0);
	else if (!ft_strcmp(buff, "sb"))
		swap_b(stu, 0);
	else if (!ft_strcmp(buff, "ss"))
		swap_both(stu, 0);
}

void	sort_by_inst(t_ps *stu, t_flags *s)
{
	char	*buff;
	int		i;

	i = 0;
	while (get_next_line(s->fd, &buff))
	{
		if (i == 0)
			buff = check_notrash(buff, stu);
		if (is_cor_inst(buff))
		{
			accept_fol_inst(buff, stu);
			if (s->v == 1 || s->c == 1)
				visualization(buff, stu, s);
			s->c_c++;
		}
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		ft_strdel(&buff);
		i++;
	}
	if (s->n == 1)
		ft_printf("Command count: %i\n", s->c_c);
}

void	checker_ex(int argc, char **argv, t_flags *s)
{
	t_ps *stu;

	if (check_arg(argv, argc))
	{
		stu = init_struct(argv, argc);
		if (stu->a == NULL)
			exit(1);
		else if (second_valid(stu->a))
		{
			sort_by_inst(stu, s);
			if (is_sort(stu->a) && stu->b == NULL)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		else
			ft_printf("Error\n");
		free_ps(stu);
	}
	else
		ft_printf("Error\n");
}
