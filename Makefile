
# all:
# 	gcc -Wall -Wextra -Werror ./src/general/*.c ./src/push_swap/*.c -L./lib/ -lftprintf -I./includes -o push_swap
# 	gcc  -Wall -Wextra -Werror ./src/general/*.c ./src/checker/*.c -L./lib/ -lftprintf -I./includes -o checker
# sfs
NAME_PUSH_SWAP = push
NAME_CHECKER = check
LIBFT_A = lib/libft/libft.a
LIBFTPRINTF_A = lib/libftprintf.a
FLAGS = -Wall -Wextra -Werror
COMP =		gcc -Wall -Wextra -Werror -c -o
PUSH_SWAP_H = -I includes/

OBJ_DIR =	./obj/
OBJ_DIR_C = ./obj_c/
OBJ_DIR_O = ./obj_o/

SRC_P_DIR =	./src/push_swap/
SRC_O_DIR = ./src/general/
SRC_C_DIR = ./src/checker/

C_P_FILE =	main_push.c \
			ft_avr_na.c \
			ft_avr_nb.c \
			ft_group.c \
			ft_insert_sort_b.c \
			ft_max_min.c \
			ft_push_swap.c \
			ft_push_swap_little.c \
			ft_which_way.c

C_O_FILE =	ft_for_list.c \
			ft_handling.c \
			ft_init_all.c \
			ft_operation_p.c \
			ft_operation_r.c \
			ft_operation_rr.c \
			ft_operation_s.c \
			ft_print_stacks.c \
			ft_sorted.c

C_C_FILE =	main_checker.c \
			ft_read_do.c

C_P_FIND =		$(addprefix $(SRC_P_DIR), $(C_P_FILE))
C_O_FIND = 		$(addprefix $(SRC_O_DIR), $(C_O_FILE))
C_C_FIND = 		$(addprefix $(SRC_C_DIR), $(C_C_FILE))

O_P_FILE =		$(C_P_FILE:%.c=%.o)
O_O_FILE =		$(C_O_FILE:%.c=%.o)
O_C_FILE =		$(C_C_FILE:%.c=%.o)

OBJ_P =		$(addprefix $(OBJ_DIR), $(O_P_FILE))
OBJ_O =		$(addprefix $(OBJ_DIR_O), $(O_O_FILE))
OBJ_C =		$(addprefix $(OBJ_DIR_C), $(O_C_FILE))

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJ_DIR) $(OBJ_P) $(OBJ_DIR_O) $(OBJ_O)
	@make -C lib/
	@gcc $(LIBFTPRINTF_A) $(OBJ_O) $(OBJ_P) -o push_swap
	@echo push_swap create

$(NAME_CHECKER): $(OBJ_DIR_C) $(OBJ_C)
	@gcc $(LIBFTPRINTF_A) $(OBJ_C) $(OBJ_O) -o checker
	@echo checker create

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_C):
			@mkdir -p $(OBJ_DIR_C)

$(OBJ_DIR_O):
			@mkdir -p $(OBJ_DIR_O)

$(OBJ_DIR)%.o: $(SRC_P_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR_O)%.o: $(SRC_O_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR_C)%.o: $(SRC_C_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@
clean:
		@rm -rf obj obj_c obj_o
		@make -C lib/ clean

fclean: clean
		@rm -rf ./checker ./push_swap
		@make -C lib/ fclean

re: fclean all

.PHONY: all clean flcean re