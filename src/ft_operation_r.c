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
	int		i;

	i = 0;
	if (stacks->size_a > 1)
	{
		while (i < stacks->size_a)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[i] = stacks->a[0];
		stacks->a[0] = 0;
	}
}

void		ft_rb(t_stack *stacks)
{
	int		i;

	i = 0;
	if (stacks->size_b > 1)
	{
		while (i < stacks->size_b)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[i] = stacks->b[0];
		stacks->b[0] = 0;
	}
}

void		ft_rr(t_stack *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
}