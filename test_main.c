/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:39:05 by cjosue            #+#    #+#             */
/*   Updated: 2019/11/04 15:39:16 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

static char			*ft_strjoin_char(char *dst, char src)
{
	char			*tmp;

	if (!(tmp = ft_strjoin(dst, &src)))
		return (NULL);
	ft_strdel(&dst);
	dst = tmp;
	return (dst);
}

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

char	ft_number_instruction(char *stdin)
{
	char	*str[4];
	int		index;

	str[0] = ft_strnew(2);
	str[0] = ft_strjoin(str[0], "sa");
	str[1] = ft_strnew(2);
	str[1] = ft_strjoin(str[1], "sb");
	str[2] = ft_strnew(2);
	str[2] = ft_strjoin(str[2], "ss");
	index = 0;
	while (index < 3)
	{
		if (!(ft_strcmp(stdin, str[index])))
			return ((char)++index);
		index++;
	}
	return ((char)++index);
}

int		main(int ac, char **av)
{
	char	*stdin;
	int		*stack_a;
	int		*stack_b;
	char	*instruction;
	int		index;

	index = 1;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(stack_a = (int*)malloc(ac)) || !(stack_b = (int*)malloc(ac)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}

	while (index < ac)
	{
		if (ft_is_number(av[index]))
			stack_a[index] = ft_atoi(av[index]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		index++;
	}
	char		ch;

	ch = 'a';
	while (get_next_line(0, &stdin) != 0)
	{
		instruction = ft_strjoin_char(instruction, ft_number_instruction(stdin));
//		printf("%s str\n", stdin);
		ft_strdel(&stdin);
	}
	index = 1;
	while (index < ac)
	{
		printf("%d ", stack_a[index]);
		index++;
	}
	index = 0;
	printf("\n");
	while (index < 3)
	{
		printf("%d  instruction\n", instruction[index]);
		index++;
	}
	return (1);
}

