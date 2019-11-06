/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:56:36 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/05 18:56:39 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_is_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!(num[i] <= '9' && num[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

void			ft_init_operation(t_ps *ps)
{
	ps->operation[0] = &ft_sa;
	ps->operation[1] = &ft_sb;
	ps->operation[2] = &ft_ss;
	ps->operation[3] = &ft_pa;
	ps->operation[4] = &ft_pb;
	ps->operation[5] = &ft_ra;
	ps->operation[6] = &ft_rb;
	ps->operation[7] = &ft_rr;
	ps->operation[8] = &ft_rra;
	ps->operation[9] = &ft_rrb;
	ps->operation[10] = &ft_rrr;
}

int				ft_init_stack(t_stack *stacks, int ac, char **av)
{
	t_array		*tmp;

	if (!(ft_create_list(stacks, ac - 1)))
		return (0);
	stacks->size_a = ac - 1;
	stacks->size_b = 0;
	tmp = stacks->a_end;
	while (--ac > 0)
	{
		if (ft_is_number(av[ac]))
			tmp->num = ft_atoi(av[ac]);
		else
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int			ft_init_comand(t_ps *ps)
{
	int			index;

	index = 0;
	while (index < 11)
	{
		if (!(ps->comand[index] = ft_strnew(4)))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		index++;
	}
	ps->comand[0] = "sa";
	ps->comand[1] = "sb";
	ps->comand[2] = "ss";
	ps->comand[3] = "pa";
	ps->comand[4] = "pb";
	ps->comand[5] = "ra";
	ps->comand[6] = "rb";
	ps->comand[7] = "rr";
	ps->comand[8] = "rra";
	ps->comand[9] = "rrb";
	ps->comand[10] = "rrr";
	return (1);
}
