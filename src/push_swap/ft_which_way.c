/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:03:19 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:03:21 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_print_operation(t_stack *stacks, t_ps *ps, int num)
{
	ps->operation[num](stacks);
	ft_putendl_fd(ps->comand[num], 1);
	if (ps->v == 1)
		ft_print_stacks(stacks, ps, num);
}

void		ft_clean_stacks(t_stack *stacks)
{
	t_array	*tmp;

	tmp = stacks->b_head;
	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
	tmp = stacks->a_head;
	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
}

int			ft_which_way(t_stack *stacks, int group, char st)
{
	int		ra;
	int		rra;
	t_array	*tmp;

	ra = 0;
	rra = 0;
	tmp = (st == 'a') ? stacks->a_head : stacks->b_head;
	while (tmp->group != group)
	{
		tmp = tmp->next;
		ra++;
	}
	tmp = (st == 'a') ? stacks->a_end : stacks->b_end;
	while (tmp->group != group)
	{
		tmp = tmp->prev;
		rra++;
	}
	if (ra <= rra + 1)
		return (1);
	return (0);
}
