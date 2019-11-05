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
	if (stacks->size_a > 1)
	{
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = stacks->a[2];
		stacks->a[2] = stacks->a[0];
		stacks->a[0] = 0;
	}
}

void		ft_sb(t_stack *stacks)
{
	if (stacks->size_b > 1)
	{
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = stacks->b[2];
		stacks->b[2] = stacks->b[0];
		stacks->b[0] = 0;
	}
}

void		ft_ss(t_stack *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}

void		ft_pa(t_stack *stacks)
{
	int		i;

	i = stacks->size_a;
	if (stacks->size_b > 0)
	{
		stacks->a[0] = stacks->b[1];
		while(i >= 0)
		{
			stacks->a[i + 1] = stacks->a[i];
			i--;
		}
		stacks->a[0] = 0;
		stacks->size_a++;
		i = 0;
		while ( i < stacks->size_b)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[0] = 0;
		stacks->b[i] = 0;
		stacks->size_b--;
	}
}

void		ft_pb(t_stack *stacks)
{
	int		i;

	i = stacks->size_b;
	if (stacks->size_a > 0)
	{
		stacks->b[0] = stacks->a[1];
		while (i >= 0)
		{
			stacks->b[i + 1] = stacks->b[i];
			i--;
		}
		stacks->b[0] = 0;
		stacks->size_b++;
		i = 0;
		while ( i < stacks->size_a)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[0] = 0;
		stacks->a[i] = 0;
		stacks->size_a--;
	}
}