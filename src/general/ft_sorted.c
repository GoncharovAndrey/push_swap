/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:01:03 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:01:05 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			ft_a_sorted(t_stack *stacks)
{
	t_array	*tmp;
	int		size;

	tmp = stacks->a_head;
	size = stacks->size_a;
	while (size-- > 1)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_is_sorted(t_stack *stacks, t_ps *ps, int ac)
{
	t_array	*tmp;

	if (ps->v == 1)
		ft_putstr("\033[31m");
	if (stacks->size_a != ac)
	{
		ft_putendl_fd("KO", 1);
		return ;
	}
	tmp = stacks->a_head;
	while (--ac > 0)
	{
		if (tmp->num > tmp->next->num)
		{
			ft_putendl_fd("KO", 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putendl_fd("OK", 1);
	ft_putstr("\033[0m");
}
