/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:02:09 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:02:11 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_ra_rra_for_sort_b(t_stack *stacks, t_ps *ps, int ra, int rra)
{
	if (ra <= rra)
	{
		while (ra-- > 0)
		{
			if (stacks->b_head->group == 1)
			{
				ft_print_operation(stacks, ps, 3);
				ra--;
			}
			if (stacks->b_head->group != 1)
				ft_print_operation(stacks, ps, 6);
		}
	}
	else
	{
		while (rra-- > 0)
		{
			if (stacks->b_head->group == 1)
				ft_print_operation(stacks, ps, 3);
			ft_print_operation(stacks, ps, 9);
		}
	}
}

void		ft_insert_sort_b(t_stack *stacks, t_ps *ps)
{
	int		ra;
	int		rra;
	t_array	*tmp;

	while (stacks->size_b > 0)
	{
		if (!(ft_find_group_b(stacks, 1)))
			ft_max_b(stacks, 1);
		tmp = stacks->b_head;
		ra = 0;
		while (tmp && tmp->group != 1)
		{
			ra++;
			tmp = tmp->next;
		}
		rra = stacks->size_b - ra;
		if (stacks->size_b > 1)
			ft_max_b(stacks, 1);
		ft_ra_rra_for_sort_b(stacks, ps, ra, rra);
		ft_print_operation(stacks, ps, 3);
		if (stacks->size_a > 1 && \
				stacks->a_head->num > stacks->a_head->next->num)
			ft_print_operation(stacks, ps, 0);
	}
}
