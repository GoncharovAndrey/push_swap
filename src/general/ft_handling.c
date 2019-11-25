/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:00:07 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/25 15:00:11 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				ft_duplicate_stack(t_stack *stacks)
{
	t_array		*tmp;
	t_array		*number;

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

int				ft_atoi_max(const char *nptr, int *flag)
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

void			ft_del_nav(char **nav, t_ps *ps)
{
	int			i;

	i = 0;
	if (ps->flag == 1)
	{
		while (nav[i])
		{
			free(nav[i]);
			i++;
		}
		free(nav);
	}
}

int				ft_is_number(char *num)
{
	int			i;

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
