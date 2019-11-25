/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:01:59 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:02:01 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			ft_find_group(t_stack *stacks, int group)
{
	t_array	*tmp;

	tmp = stacks->a_head;
	while (tmp != NULL)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_find_group_b(t_stack *stacks, int group)
{
	t_array	*tmp;

	tmp = stacks->b_head;
	while (tmp != NULL)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		ft_group(t_stack *stacks, int len, int group)
{
	while (len-- > 0 && ft_find_group(stacks, 0))
	{
		ft_min_a(stacks, group);
	}
}

void		ft_group_b(t_stack *stacks, int len, int group)
{
	while (len-- > 0 && ft_find_group_b(stacks, 0))
	{
		ft_max_b(stacks, group);
	}
}
