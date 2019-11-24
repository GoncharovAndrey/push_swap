/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:06:15 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/24 20:06:17 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_sa(t_stack *stacks)
{
	t_array *tmp;
	t_array *tmp2;

	tmp = stacks->a_head;
	tmp2 = NULL;
	if (stacks->size_a > 1)
	{
		tmp2 = stacks->a_head->next;
		stacks->a_head = tmp2;
		stacks->a_head->prev = NULL;
		tmp->next = tmp2->next;
		tmp->prev = tmp2;
		stacks->a_head->next = tmp;
		if (tmp->next)
			tmp->next->prev = tmp;
		if (stacks->size_a == 2)
			stacks->a_end = stacks->a_head->next;
	}
}

void		ft_sb(t_stack *stacks)
{
	t_array *tmp;
	t_array *tmp2;

	tmp = stacks->b_head;
	tmp2 = NULL;
	if (stacks->size_b > 1)
	{
		tmp2 = stacks->b_head->next;
		stacks->b_head = tmp2;
		stacks->b_head->prev = NULL;
		tmp->next = tmp2->next;
		tmp->prev = tmp2;
		stacks->b_head->next = tmp;
		if (tmp->next)
			tmp->next->prev = tmp;
		if (stacks->size_b == 2)
			stacks->b_end = stacks->b_head->next;
	}
}

void		ft_ss(t_stack *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}
