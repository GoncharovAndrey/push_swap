/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_sp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:21:30 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 16:21:32 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	}
}

void		ft_ss(t_stack *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}

void		ft_pa(t_stack *stacks)
{
	t_array	*tmp;

	if (stacks->size_b > 0)
	{
		tmp = stacks->b_head;
		if (stacks->size_b == 1)
			stacks->b_head = NULL;
		else
		{
			stacks->b_head = stacks->b_head->next;
			stacks->b_head->prev = NULL;
		}
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

void		ft_pb(t_stack *stacks)
{
	t_array	*tmp;

	if (stacks->size_a > 0)
	{
		tmp = stacks->a_head;
		if (stacks->size_a == 1)
			stacks->a_head = NULL;
		else
		{
			stacks->a_head = stacks->a_head->next;
			stacks->a_head->prev = NULL;
		}
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