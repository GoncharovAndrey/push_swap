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

#include "../includes/push_swap.h"
#include <stdio.h>

void		ft_for_print_stacks(t_stack *stacks)
{
	t_array	*tmp;
	t_array	*tmp_b;

	tmp = stacks->a_head;
	tmp_b = stacks->b_head;
	while (tmp || tmp_b)
	{
		printf("\033[1;31;46m");
		if (tmp)
		{
			printf("%11d ", tmp->num);
			tmp = tmp->next;
		}
		else
			printf("%12c", ' ');
		printf("\033[30m|\033[32m");
		if (tmp_b)
		{
			printf("%11d ", tmp_b->num);
			tmp_b = tmp_b->next;
		}
		else
			printf("%12c", ' ');
		printf("\033[0m\n");
	}
}

void		ft_print_stacks(t_stack *stacks, t_ps *ps, int i)
{
	printf("\033[1;33;47m%11s : %-11s\033[0m\n", "COMAND", ps->comand[i]);
	printf("\033[1;31;46m%10s  \033[32m%11s  \033[0m\n", "stack A", "stack B");
	printf("\033[1;30;46m-------------------------\033[0m\n");
	ft_for_print_stacks(stacks);
	printf("\033[1;30;46m-------------------------\033[0m\n\n");
}

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
