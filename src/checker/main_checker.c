/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:02:30 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 19:02:32 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

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
