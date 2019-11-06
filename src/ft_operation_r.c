/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:21:45 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 16:21:48 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_ra(t_stack *stacks)
{
	t_array	*tmp;

	if(stacks->size_a > 1)
	{
		if (stacks->size_a == 2)
			ft_sa(stacks);
		else
		{
			tmp = stacks->a_head;
			stacks->a_head = stacks->a_head->next;
			stacks->a_head->prev = NULL;
			tmp->next = NULL;
			tmp->prev = stacks->a_end;
			stacks->a_end->next = tmp;
			stacks->a_end = tmp;
		}
	}
}

void		ft_rb(t_stack *stacks)
{
	t_array	*tmp;

	if(stacks->size_b > 1)
	{
		if (stacks->size_b == 2)
			ft_sb(stacks);
		else
		{
			tmp = stacks->b_head;
			stacks->b_head = stacks->b_head->next;
			stacks->b_head->prev = NULL;
			tmp->next = NULL;
			tmp->prev = stacks->b_end;
			stacks->b_end->next = tmp;
			stacks->b_end = tmp;
		}
	}
}

void		ft_rr(t_stack *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
}