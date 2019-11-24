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
#include <stdio.h>
#include <limits.h>


int		ft_duplicate_stack(t_stack *stacks)
{
	t_array	*tmp;
	t_array	*number;

	number = stacks->a_head;
	while (number != stacks->a_end)
	{
		tmp = number->next;
		while (tmp != stacks->a_end->next)
		{
			if (number->num == tmp->num)
				return (0);
			tmp = tmp->next;
		}
		number = number->next;
	}
	return (1);
}

int	ft_atoi_max(const char *nptr, int *flag)
{
	size_t		i;
	long int	res;
	int			z;

	res = 0;
	i = 0;
	z = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	z = nptr[i] == '-' ? -1 : 1;
	i = nptr[i] == '-' || nptr[i] == '+' ? i + 1 : i + 0;

//	if (nptr[i] == '-')
//	{
//		i++;
//		z = -1;
//	}
//	else if (nptr[i] == '+')
//		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((z * res) > INT_MAX || (z * res) < INT_MIN)
		{
			*flag = 0;
			return (-1);
		}
		i++;
	}
	return (res * z);
}

int			ft_is_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
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
	int			flag;

	if (!(ft_create_list(stacks, ac )))
		return (0);
	stacks->size_a = ac;
	stacks->size_b = 0;
	tmp = stacks->a_end;
	while (--ac >= 0)
	{
		if (ft_is_number(av[ac]))
		{
			if ((tmp->num = ft_atoi_max(av[ac], &flag)) == -1)
			{
				if (flag == 0)
					return (0);
			}
		}
		else
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void		ft_init_comand(t_ps *ps)
{
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
}


void		ft_init_ps(t_ps *ps)
{
	ft_init_comand(ps);
	ft_init_operation(ps);
}