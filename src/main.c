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

void		ft_is_sorted(t_stack *stacks, int ac)
{
	t_array	*tmp;

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
}

int		main(int ac, char **av)
{
	t_stack	stacks;
	t_ps	ps;
	char	**nav;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	nav = !ft_strcmp(av[1], "-v") ? av + 2 : av + 1;
	ac  -= !ft_strcmp(av[1], "-v") ? 2 : 1;

	if (ac == 1)
	{
		nav = ft_strsplit(nav[0], 32);
		ac = 0;
		while (nav[ac])
			ac++;
	}
	if (!(ft_init_stack(&stacks, ac, nav)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(ft_init_comand(&ps)))
		return (0);
	ft_init_operation(&ps);
	if(!(ft_read_do(&ps, &stacks, av[1])))
		return (0);
	ft_is_sorted(&stacks, ac);
	ft_del_list(&stacks);
	return (0);
}
