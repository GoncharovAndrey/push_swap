/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:56:36 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 18:56:39 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				ft_init_flag(t_ps *ps, char ***nav, char **av, int ac)
{
	ps->flag = 0;
	*nav = !ft_strcmp(av[1], "-v") ? av + 2 : av + 1;
	ac -= !ft_strcmp(av[1], "-v") ? 2 : 1;
	ps->v = !ft_strcmp(av[1], "-v") ? 1 : 0;
	if (ac == 1)
	{
		if (!(*nav = ft_strsplit(*nav[0], 32)))
			return (0);
		ac = 0;
		ps->flag = 1;
		while (nav[0][ac])
			ac++;
	}
	return (ac);
}

void			ft_init_operation(t_ps *ps)
{
	ps->operation[0] = &ft_sa;
	ps->operation[1] = &ft_sb;
	ps->operation[2] = &ft_ss;
	ps->operation[3] = &ft_pa;
	ps->operation[4] = &ft_pb;
	ps->operation[5] = &ft_ra;
	ps->operation[6] = &ft_rb;
	ps->operation[7] = &ft_rr;
	ps->operation[8] = &ft_rra;
	ps->operation[9] = &ft_rrb;
	ps->operation[10] = &ft_rrr;
}

int				ft_init_stack(t_stack *stacks, int ac, char **av)
{
	t_array		*tmp;
	int			flag;

	flag = 1;
	if (!(ft_create_list(stacks, ac)))
		return (0);
	stacks->size_a = ac;
	stacks->size_b = 0;
	tmp = stacks->a_end;
	while (--ac >= 0)
	{
		if (ft_is_number(av[ac]))
		{
			if ((tmp->num = ft_atoi_max(av[ac], &flag)) == -1)
			{
				if (flag == 0)
					return (0);
			}
		}
		else
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void			ft_init_comand(t_ps *ps)
{
	ps->comand[0] = "sa";
	ps->comand[1] = "sb";
	ps->comand[2] = "ss";
	ps->comand[3] = "pa";
	ps->comand[4] = "pb";
	ps->comand[5] = "ra";
	ps->comand[6] = "rb";
	ps->comand[7] = "rr";
	ps->comand[8] = "rra";
	ps->comand[9] = "rrb";
	ps->comand[10] = "rrr";
}

int				ft_init_all(t_stack *stacks, t_ps *ps, int ac, char **av)
{
	if (!(ft_init_stack(stacks, ac, av)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (!(ft_duplicate_stack(stacks)))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_init_comand(ps);
	ft_init_operation(ps);
	return (1);
}
