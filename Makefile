
all:
	gcc main_push.c ./src/ft_for_list.c ./src/ft_init_all.c ./src/ft_operation_*.c -L./libft -lft -I./includes -o push
	gcc ./src/*.c -L./libft -lft -I./includes -o checker

checker:
	gcc ./src/*.c -L./libft -lft -I./includes -o checker

