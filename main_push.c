/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:58:37 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/15 11:58:39 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int		ft_a_sorted(t_stack *stacks)
{
	t_array	*tmp;
	int		size;

	tmp = stacks->a_head;
	size = stacks->size_a;
	while (size-- > 1)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
/*
int		ft_b_sorted(t_stack *stacks)
{
	t_array	*tmp;
	int		size;

	tmp = stacks->b_head;
	size = stacks->size_b;
	while (size-- > 1)
	{
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}*/
typedef struct	s_min
{
	int			min;
	int			min_pos;
}				t_min;

void			ft_stacks_min(t_stack *stacks, t_min *m)
{
	t_array	*tmp;
	int		i;

	i = 1;
	m->min = stacks->a_head->num;
	m->min_pos = 1;
	tmp = stacks->a_head;
	while (i <=  stacks->size_a - 1)
	{
		if (m->min > tmp->next->num)
		{
			m->min = tmp->next->num;
			m->min_pos = i + 1;
		}
		tmp = tmp->next;
		i++;
	}
}

void		ft_push_swap(t_stack *stacks, t_ps *ps)
{
	t_min	m;
	int		oprtn;

	while (!ft_a_sorted(stacks))
	{
		ft_stacks_min(stacks, &m);
		oprtn = (m.min_pos <= stacks->size_a / 2 ) ? 5 : 8;
//		if (stacks->a_head->num > stacks->a_head->next->num && stacks->a_head->next->num != m.min)
//		{
//			ps->operation[0](stacks);
//			ft_putendl_fd(ps->comand[0], 1);
//		}
		if (ft_a_sorted(stacks) == 1)
			break;
		while (stacks->a_head->num != m.min)
		{
//			if (stacks->a_head->num > stacks->a_head->next->num && stacks->a_head->next->num != m.min)
//			{
//				ps->operation[0](stacks);
//				ft_putendl_fd(ps->comand[0], 1);
//			}
			ps->operation[oprtn](stacks);
			ft_putendl_fd(ps->comand[oprtn], 1);
		}
		if (ft_a_sorted(stacks))
			break;
		ps->operation[4](stacks);
		ft_putendl_fd(ps->comand[4], 1);
	}
	while (stacks->size_b != 0)
	{
		ps->operation[3](stacks);
		ft_putendl_fd(ps->comand[3], 1);
	}
}

int		main(int ac, char **av)
{
	t_stack	stacks;
	t_ps	ps;
	char	**nav;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	nav = av + 1;
	ac--;
	if (ac == 1)
	{
		nav = ft_strsplit(nav[0], 32);
		ac = 0;
		while (nav[ac])
			ac++;
	}
	if (!(ft_init_stack(&stacks, ac, nav)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(ft_init_comand(&ps)))
		return (0);
	ft_init_operation(&ps);

	ft_push_swap(&stacks, &ps);

//	ft_is_sorted(&stacks, ac);
	return (1);
}