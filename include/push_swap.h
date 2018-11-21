/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yholub <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:36:47 by yholub            #+#    #+#             */
/*   Updated: 2018/07/31 15:22:38 by yholub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf/ft_printf.h"

typedef struct		s_stk
{
	int				val;
	struct s_stk	*next;
}					t_stk;

typedef struct		s_cou
{
	int				count;
	int				bot;
	struct s_cou	*next;
}					t_cou;

typedef struct		s_op
{
	char			*op;
	struct s_op		*next;
}					t_op;

typedef struct		s_ps
{
	t_stk			*a;
	t_stk			*b;
	t_cou			*cou;
	int				count;
	t_op			*op;
}					t_ps;

typedef struct		s_flags
{
	int				h;
	int				v;
	int				n;
	int				c;
	int				r;
	int				c_c;
	int				f_c;
	int				fd;
}					t_flags;

void				free_ps(t_ps *stu);
void				ft_get_fd(t_flags *s, char *file);
void				show_us(int i);
void				visualization(char *buff, t_ps *stu, t_flags *s);
void				checker_ex(int argc, char **argv, t_flags *s);
void				del_one_and_rep(t_op *op);
int					is_need_sh_up_b(t_stk *lst, int med);
int					is_need_shift_up(t_stk *lst, int med);
void				del_two_ops(t_op *op);
int					is_nessesary(int mid, t_stk *stu);
int					is_ssesary(int mid, t_stk *stu);
void				change_this_com(t_op *op);
int					is_another_one(t_op *op);
void				optimize_op_num(t_op *op);
int					is_cor_inst(char *buff);
t_ps				*init_struct(char **mass, int len);
void				put_op(t_ps *stu, char *str);
void				find_pre_last_block(t_ps *stu);
int					*fill_sort(int *mas, int size);
int					*lst_to_mas(t_stk *lst, int size);
int					add_to_pb(t_ps *stu, t_cou *temp, int h_m);
int					add_to_ra(t_ps *stu, int bot);
t_cou				*init_count(void);
int					shiftup_on_n(t_ps *stu, int bot);
int					sort_rel_med(t_ps *stu, int h_m);
int					sort_mr_th_tr(t_ps *stu, int h_m);
void				del_last_list(t_ps *stu);
int					mid_to_b(t_ps *stu, int len);
int					min_val(int *mass, int size);
t_cou				*find_last_block(t_cou *lst);
void				push_back(t_ps *stu);
void				sort_first_three(t_ps *stu);
void				sort_ps(t_ps *stu);
int					find_size(t_stk *lst);
int					find_mid_val(t_stk *lst);
int					is_sort(t_stk *lst);
t_stk				*make_lst(char **mass);
t_stk				*find_last(t_stk *lst);
t_stk				*find_prelast(t_stk *lst);
void				rev_rot_a(t_ps *stu, int i);
void				rev_rot_b(t_ps *stu, int i);
void				rev_rot_both(t_ps *stu, int i);
void				rotate_a(t_ps *stu, int i);
void				rotate_b(t_ps *stu, int i);
void				rotate_both(t_ps *stu, int i);
void				push_b(t_ps *stu, int i);
void				swap_a(t_ps *stu, int i);
void				swap_b(t_ps *stu, int i);
void				push_a(t_ps *stu, int i);
void				swap_both(t_ps *stu, int i);
int					second_valid(t_stk *stu);
int					mass_len(char **mass);
t_stk				*cr_newnode(char *str);
char				**get_mass(char **mass, int len);
void				free_mass(char **temp);
int					check_arg(char **s, int len);

#endif
