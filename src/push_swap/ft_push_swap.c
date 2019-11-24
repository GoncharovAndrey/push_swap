/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:28:56 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/24 19:28:59 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_push_swap(t_stack *stacks, t_ps *ps)
{
	int		i;

	if (ft_a_sorted(stacks))
		return ;
	if (stacks->size_a <= 5)
	{
		ft_push_swap_little(stacks, ps);
		return ;
	}
	if (stacks->size_a / 2 < 124)
		ft_avr_na(stacks, ps, 15, 1);
	else
	{
		i = ft_avr_a(stacks, ps, stacks->size_a);
		while (i > 50)
		{
			i = ft_avr_nb(stacks, ps, i / 5, 1);
			i = ft_avr_na(stacks, ps, i / 5, 1);
		}
	}
	ft_insert_sort_b(stacks, ps);
}
