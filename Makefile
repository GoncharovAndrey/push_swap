
all:
	gcc main_push.c ft_push_swap_rec.c push_swap_in.c ./src/ft_for_list.c ./src/ft_init_all.c ./src/ft_operation_*.c -L./libft -lft -I./includes -o push
	gcc ./src/*.c -L./libft -lft -I./includes -o checker

checker:
	gcc ./src/*.c -L./libft -lft -I./includes -o checker

