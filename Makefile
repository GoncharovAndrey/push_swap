
all:
	gcc -Wall -Wextra -Werror ./src/general/*.c ./src/push_swap/*.c -L./libft -lft -I./includes -o push_swap
	gcc  -Wall -Wextra -Werror ./src/general/*.c ./src/checker/*.c -L./libft -lft -I./includes -o checker


