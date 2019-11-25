/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avr_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:04:01 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:04:02 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_ra_for_nb(t_stack *stacks, t_ps *ps, int group, int group_next)
{
	while (stacks->b_head->group != group)
	{
		while (stacks->b_head->group == group_next)
		{
			ft_print_operation(stacks, ps, 3);
			if (group_next % 2 == 0)
			{
				if (stacks->a_head->group != group_next && \
						stacks->a_head->group != group)
					ft_print_operation(stacks, ps, 7);
				else
					ft_print_operation(stacks, ps, 5);
			}
		}
		if (stacks->b_head->group != group)
			ft_print_operation(stacks, ps, 6);
	}
}

void		ft_rra_for_nb(t_stack *stacks, t_ps *ps, int group, int group_next)
{
	while (stacks->b_head->group != group)
	{
		while (stacks->b_head->group == group_next)
		{
			ft_print_operation(stacks, ps, 3);
			if (group_next % 2 == 0)
				ft_print_operation(stacks, ps, 5);
		}
		ft_print_operation(stacks, ps, 9);
	}
}

int			ft_avr_nb(t_stack *stacks, t_ps *ps, int size, int group)
{
	int		group_next;

	while (stacks->size_b != 0)
	{
		if (!(ft_find_group_b(stacks, group)))
			ft_group_b(stacks, size, group);
		if (!ft_find_group_b(stacks, group + 1))
		{
			group_next = group + 1;
			ft_group_b(stacks, size, group_next);
		}
		while (ft_find_group_b(stacks, group))
		{
			if (ft_which_way(stacks, group, 'b'))
				ft_ra_for_nb(stacks, ps, group, group_next);
			else
				ft_rra_for_nb(stacks, ps, group, group_next);
			ft_print_operation(stacks, ps, 3);
			if (group % 2 == 0)
				ft_print_operation(stacks, ps, 5);
		}
		group++;
	}
	ft_clean_stacks(stacks);
	return (size);
}
