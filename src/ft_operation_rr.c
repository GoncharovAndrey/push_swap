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
	int		i;

	i = stacks->size_a;
	if (stacks->size_a > 1)
	{
		stacks->a[0] = stacks->a[stacks->size_a];
		stacks->a[stacks->size_a] = 0;
		while(i >= 0)
		{
			stacks->a[i + 1] = stacks->a[i];
			i--;
		}
		stacks->a[0] = 0;
	}
}

void		ft_rrb(t_stack *stacks)
{
	int		i;

	i = stacks->size_b;
	if (stacks->size_b > 1)
	{
		stacks->b[0] = stacks->b[stacks->size_b];
		stacks->b[stacks->size_b] = 0;
		while(i >= 0)
		{
			stacks->b[i + 1] = stacks->b[i];
			i--;
		}
		stacks->b[0] = 0;
	}
}

void		ft_rrr(t_stack *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
}
