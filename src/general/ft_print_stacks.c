/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:00:42 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:00:45 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ft_for_print_stacks(t_stack *stacks)
{
	t_array	*tmp;
	t_array	*tmp_b;

	tmp = stacks->a_head;
	tmp_b = stacks->b_head;
	while (tmp || tmp_b)
	{
		ft_printf("\033[1;31;46m");
		if (tmp)
		{
			ft_printf("%11d ", tmp->num);
			tmp = tmp->next;
		}
		else
			ft_printf("%12c", ' ');
		ft_printf("\033[30m|\033[32m");
		if (tmp_b)
		{
			ft_printf("%11d ", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		else
			ft_printf("%12c", ' ');
		ft_printf("\033[0m\n");
	}
}

void		ft_print_stacks(t_stack *stacks, t_ps *ps, int i)
{
	ft_printf("\033[1;33;47m%11s : %-11s\033[0m\n", "COMAND", ps->comand[i]);
	ft_printf("\033[1;31;46m%10s\033[32m%13s  \033[0m\n", "stack A", "stack B");
	ft_printf("\033[1;30;46m-------------------------\033[0m\n");
	ft_for_print_stacks(stacks);
	ft_printf("\033[1;30;46m-------------------------\033[0m\n\n");
}
