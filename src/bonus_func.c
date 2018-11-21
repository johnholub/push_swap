/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:26:05 by yholub            #+#    #+#             */
/*   Updated: 2018/08/07 13:26:06 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_get_fd(t_flags *s, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("Not valid file\n");
		exit(1);
	}
	s->fd = fd;
}

void	show_us(int i)
{
	if (i == 1)
		ft_printf("________________HELP_________________\n");
	else
		ft_printf("________________Usage________________\n");
	ft_printf("| %-14s %-19s|\n", "-h", "<help>");
	ft_printf("| %-14s %-19s|\n", "-v", "<visualization>");
	ft_printf("| %-14s %-19s|\n", "-n", "<number of command>");
	ft_printf("| %-14s %-19s|\n", "-c", "<print command>");
	ft_printf("| %-14s %-19s|\n", "-r [file name]", "<input from file>");
	ft_printf("|___________________________________|\n");
}
