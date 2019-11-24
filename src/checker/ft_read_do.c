/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:00:16 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 19:00:18 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			ft_number_operation(char *stdin, t_ps *ps)
{
	int		index;

	index = 0;
	while (index < 11)
	{
		if (!(ft_strcmp(stdin, ps->comand[index])))
			return (index);
		index++;
	}
	return (index);
}

int			ft_read_do(t_ps *ps, t_stack *stacks)
{
	int		i;
	char	*stdin;

	i = 0;
	while (get_next_line(0, &stdin) != 0)
	{
		if ((i = ft_number_operation(stdin, ps)) == 11)
		{
			ft_putstr_fd("Error\n", 2);
			ft_strdel(&stdin);
			return (0);
		}
		ps->operation[i](stacks);
		if (ps->v == 1)
			ft_print_stacks(stacks, ps, i);
		ft_strdel(&stdin);
	}
	return (1);
}
