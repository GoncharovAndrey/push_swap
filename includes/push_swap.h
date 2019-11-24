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
# include <limits.h>
# include <stdio.h>

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

typedef struct	s_push_swap
{
	char		*comand[11];
	void		(*operation[11])(t_stack *stacks);
	int			v;
	int			flag;
}				t_ps;

/*______________general_purpose_functions_______*/
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
void			ft_init_operation(t_ps *ps);
void			ft_init_comand(t_ps *ps);
int				ft_init_flag(t_ps *ps, char ***nav, char **av, int ac);
int				ft_init_stack(t_stack *stacks, int ac, char **av);
int				ft_init_all(t_stack *stacks, t_ps *ps, int ac, char **av);
t_array			*ft_create_elem(void);
int				ft_create_list(t_stack *stacks, int ac);
void			ft_del_list(t_stack *stacks);
void			ft_is_sorted(t_stack *stacks, t_ps *ps, int ac);
int				ft_a_sorted(t_stack *stacks);
int				ft_is_number(char *num);
int				ft_duplicate_stack(t_stack *stacks);
void			ft_del_nav(char **nav, t_ps *ps);
int				ft_atoi_max(const char *nptr, int *flag);
void			ft_print_stacks(t_stack *stacks, t_ps *ps, int i);
/*______________function_for_checker________________________*/
int				ft_read_do(t_ps *ps, t_stack *stacks);
int				ft_number_operation(char *stdin, t_ps *ps);
/*______________function_for_push_swap______________________*/
void			ft_push_swap(t_stack *stacks, t_ps *ps);
void			ft_push_swap_little(t_stack *stacks, t_ps *ps);
void			ft_group(t_stack *stacks, int len, int group);
void			ft_group_b(t_stack *stacks, int len, int group);
int				ft_find_group(t_stack *stacks, int group);
int				ft_find_group_b(t_stack *stacks, int group);
int				ft_min_a(t_stack *stacks, int group);
int				ft_max_b(t_stack *stacks, int group);
int				ft_avr_a(t_stack *stacks, t_ps *ps, int size);
int				ft_avr_na(t_stack *stacks, t_ps *ps, int size, int group);
int				ft_avr_nb(t_stack *stacks, t_ps *ps, int size, int group);
void			ft_insert_sort_b(t_stack *stacks, t_ps *ps);
int				ft_which_way(t_stack *stacks, int group, char st);
void			ft_clean_stacks(t_stack *stacks);
void			ft_print_operation(t_stack *stacks, t_ps *ps, int num);

#endif


