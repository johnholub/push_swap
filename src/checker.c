/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 11:41:50 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:17:54 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		is_flag(char *f)
{
	if (!f)
		return (0);
	if (!ft_strcmp(f, "-v"))
		return (1);
	if (!ft_strcmp(f, "-h"))
		return (1);
	if (!ft_strcmp(f, "-c"))
		return (1);
	if (!ft_strcmp(f, "-n"))
		return (1);
	if (!ft_strcmp(f, "-r"))
		return (1);
	return (0);
}

int		count_flags(t_flags *s)
{
	int	res;

	if (s->c > 1 || s->v > 1 || s->r > 1 || s->n > 1 || s->h > 1)
		return (-1);
	res = s->c + s->v + s->r + s->r + s->n + s->h;
	return (res);
}

void	search_flags(t_flags *s, char **argv, int len)
{
	int i;

	i = 1;
	while (is_flag(argv[i]) && i < len)
	{
		if (!ft_strcmp(argv[i], "-v"))
			s->v++;
		if (!ft_strcmp(argv[i], "-h"))
			s->h++;
		if (!ft_strcmp(argv[i], "-c"))
			s->c++;
		if (!ft_strcmp(argv[i], "-n"))
			s->n++;
		if (!ft_strcmp(argv[i], "-r"))
			s->r++;
		i++;
	}
	s->f_c = count_flags(s);
}

t_flags	*init_flags(void)
{
	t_flags	*res;

	res = (t_flags *)malloc(sizeof(t_flags));
	res->h = 0;
	res->c = 0;
	res->f_c = 0;
	res->n = 0;
	res->r = 0;
	res->v = 0;
	res->c_c = 0;
	res->fd = 0;
	return (res);
}

int		main(int argc, char **argv)
{
	t_flags	*s;

	if (argc > 1)
	{
		s = init_flags();
		search_flags(s, argv, argc);
		if (s->f_c == -1 || s->h == 1)
		{
			show_us(s->h);
			exit(1);
		}
		if (s->r == 1)
			ft_get_fd(s, argv[s->f_c]);
		checker_ex(argc - s->f_c, argv + s->f_c, s);
	}
	return (0);
}
