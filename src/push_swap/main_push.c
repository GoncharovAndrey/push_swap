/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:58:37 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/15 11:58:39 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack	stacks;
	t_ps	ps;
	char	**nav;

	if (ac == 1)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if ((ac = ft_init_flag(&ps, &nav, av, ac)))
		if (ft_init_all(&stacks, &ps, ac, nav))
			ft_push_swap(&stacks, &ps);
	ft_del_list(&stacks);
	ft_del_nav(nav, &ps);
	return (0);
}
