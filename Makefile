
all:
	gcc -Wall -Wextra -Werror ./src/general/*.c ./src/push_swap/*.c -L./lib/ -lftprintf -I./includes -o push_swap
	gcc  -Wall -Wextra -Werror ./src/general/*.c ./src/checker/*.c -L./lib/ -lftprintf -I./includes -o checker


