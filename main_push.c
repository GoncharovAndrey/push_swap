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

#include "includes/push_swap.h"

int		ft_a_sorted(t_stack *stacks)
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
	if ((ac = ft_init_flag(&ps, &nav, av, ac)))
		if (ft_init_all(&stacks, &ps, ac, nav))
			ft_push_swap_in(&stacks, &ps);
	ft_del_list(&stacks);
	ft_del_nav(nav, &ps);
	return (0);
}
