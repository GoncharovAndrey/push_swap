/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:07:11 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/24 20:07:13 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_pa_b_head(t_stack *stacks)
{
	if (stacks->size_b == 1)
	{
		stacks->b_head = NULL;
		stacks->b_end = NULL;
	}
	else
	{
		stacks->b_head = stacks->b_head->next;
		stacks->b_head->prev = NULL;
	}
}

void		ft_pa(t_stack *stacks)
{
	t_array	*tmp;

	if (stacks->size_b > 0)
	{
		tmp = stacks->b_head;
		ft_pa_b_head(stacks);
		if (stacks->size_a == 0)
		{
			stacks->a_head = tmp;
			stacks->a_head->next = NULL;
			stacks->a_end = stacks->a_head;
		}
		else
		{
			tmp->next = stacks->a_head;
			stacks->a_head->prev = tmp;
			stacks->a_head = tmp;
		}
		stacks->size_b--;
		stacks->size_a++;
	}
}

void		ft_pb_a_head(t_stack *stacks)
{
	if (stacks->size_a == 1)
	{
		stacks->a_head = NULL;
		stacks->a_head = NULL;
	}
	else
	{
		stacks->a_head = stacks->a_head->next;
		stacks->a_head->prev = NULL;
	}
}

void		ft_pb(t_stack *stacks)
{
	t_array	*tmp;

	if (stacks->size_a > 0)
	{
		tmp = stacks->a_head;
		ft_pb_a_head(stacks);
		if (stacks->size_b == 0)
		{
			stacks->b_head = tmp;
			stacks->b_head->next = NULL;
			stacks->b_end = stacks->b_head;
		}
		else
		{
			tmp->next = stacks->b_head;
			stacks->b_head->prev = tmp;
			stacks->b_head = tmp;
		}
		stacks->size_a--;
		stacks->size_b++;
	}
}
