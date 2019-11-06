/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:22:16 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 16:22:18 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_rra(t_stack *stacks)
{
	t_array	*tmp;

	if (stacks->size_a > 1)
	{
		if (stacks->size_a == 2)
			ft_sa(stacks);
		else
		{
			tmp = stacks->a_end;
			stacks->a_end = stacks->a_end->prev;
			stacks->a_end->next = NULL;
			tmp->next = stacks->a_head;
			tmp->prev = NULL;
			stacks->a_head->prev = tmp;
			stacks->a_head = tmp;
		}
	}
}

void		ft_rrb(t_stack *stacks)
{
	t_array	*tmp;

	if (stacks->size_b > 1)
	{
		if (stacks->size_b == 2)
			ft_sb(stacks);
		else
		{
			tmp = stacks->b_end;
			stacks->b_end = stacks->b_end->prev;
			stacks->b_end->next = NULL;
			tmp->next = stacks->b_head;
			tmp->prev = NULL;
			stacks->b_head->prev = tmp;
			stacks->b_head = tmp;
		}
	}
}

void		ft_rrr(t_stack *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
}
