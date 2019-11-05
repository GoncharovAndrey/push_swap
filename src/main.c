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
	int		i;

	i = 1;
	if (stacks->size_a != (ac - 1))
	{
		ft_putstr_fd("KO\n", 0);
		return ;
	}
	while (i < (ac - 1))
	{
		if (stacks->a[i] > stacks->a[i + 1])
		{
			ft_putstr_fd("KO\n", 0);
			return ;
		}
		i++;
	}
	ft_putstr_fd("OK\n", 1);
}

int		main(int ac, char **av)
{
	t_stack	stacks;
	t_ps	ps;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(ft_init_stack(&stacks, ac, av)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(ft_init_comand(&ps)))
		return (0);
	ft_init_operation(&ps);
	if (!(ft_read_do(&ps, &stacks)))
		return (0);
	ft_is_sorted(&stacks, ac);
	return (1);
}
