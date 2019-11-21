/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:13:52 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 16:13:54 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_array
{
	int				num;
	struct s_array	*next;
	struct s_array	*prev;
	int				group;
}					t_array;

typedef struct	s_stack
{
	t_array		*a_head;
	t_array		*a_end;
	t_array		*b_head;
	t_array		*b_end;
	int			size_a;
	int			size_b;
}				t_stack;

typedef struct	s_recurse
{
	int			*arr_com;
	int			*arr_res;
	int			lenght;
	int			i;
}				t_rec;

typedef struct	s_push_swap
{
	char		*comand[11];
	void		(*operation[11])(t_stack *stacks);
	int			(*oper[11])(t_stack *stacks, t_rec *rec);
}				t_ps;


void			ft_sa(t_stack *stacks);
void			ft_sb(t_stack *stacks);
void			ft_ss(t_stack *stacks);
void			ft_pa(t_stack *stacks);
void			ft_pb(t_stack *stacks);
void			ft_ra(t_stack *stacks);
void			ft_rb(t_stack *stacks);
void			ft_rr(t_stack *stacks);
void			ft_rra(t_stack *stacks);
void			ft_rrb(t_stack *stacks);
void			ft_rrr(t_stack *stacks);
int				ft_read_do(t_ps *ps, t_stack *stacks, char *av);
int				ft_number_operation(char *stdin, t_ps *ps);
void			ft_init_operation(t_ps *ps);
int				ft_init_stack(t_stack *stacks, int ac, char **av);
int				ft_init_comand(t_ps *ps);
int				ft_is_number(char *num);
void			ft_is_sorted(t_stack *stacks, int ac);
int				ft_create_list(t_stack *stacks, int ac);
void			ft_del_list(t_stack *stacks);
t_array			*ft_create_elem(void);


void			ft_init_rec(t_rec *rec, t_ps *ps, int len);
int				ft_sa_rec(t_stack *stacks, t_rec *rec);
int				ft_sb_rec(t_stack *stacks, t_rec *rec);
int				ft_ss_rec(t_stack *stacks, t_rec *rec);
int				ft_pa_rec(t_stack *stacks, t_rec *rec);
int				ft_pb_rec(t_stack *stacks, t_rec *rec);
int				ft_ra_rec(t_stack *stacks, t_rec *rec);
int				ft_rb_rec(t_stack *stacks, t_rec *rec);
int				ft_rr_rec(t_stack *stacks, t_rec *rec);
int				ft_rra_rec(t_stack *stacks, t_rec *rec);
int				ft_rrb_rec(t_stack *stacks, t_rec *rec);
int				ft_rrr_rec(t_stack *stacks, t_rec *rec);
void			ft_push_swap_rec(t_stack *stacks, t_rec *rec, t_ps *ps);
int				ft_a_sorted_ac(t_stack *stacks);


void		ft_push_swap_in(t_stack *stacks, t_ps *ps);

#endif


