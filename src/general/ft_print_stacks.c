
#include "../../includes/push_swap.h"

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
