/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:02:30 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 19:02:32 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void		ft_is_sorted(t_stack *stacks, t_ps *ps, int ac)
{
	t_array	*tmp;

	if (ps->v == 1)
		ft_putstr("\033[31m");
	if (stacks->size_a != ac)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	tmp = stacks->a_head;
	while (--ac > 0)
	{
		if (tmp->num > tmp->next->num)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("OK\n", 1);
	ft_putstr("\033[0m");
}

int			main(int ac, char **av)
{
	t_stack	stacks;
	t_ps	ps;
	char	**nav;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if ((ac = ft_init_flag(&ps, &nav, av, ac)))
		if (ft_init_all(&stacks, &ps, ac, nav))
			if (ft_read_do(&ps, &stacks))
				ft_is_sorted(&stacks, &ps, ac);
	ft_del_list(&stacks);
	ft_del_nav(nav, &ps);
	return (0);
}
