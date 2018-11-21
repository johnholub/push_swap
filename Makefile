NAME_CH = checker

NAME_PS = push_swap

SRC_SRC = ./src/com_list_1.c ./src/com_list_2.c ./src/litle_f.c ./src/validation_ps.c ./src/nod_op.c \
	./src/sort_ps.c ./src/find_size.c ./src/small_add.c ./src/sort_funk.c ./src/push_back.c \
	./src/sort_mtt.c ./src/sort_rel_med.c ./src/checker_func.c  ./src/optimize.c ./src/optimize_search.c \
	./src/is_need_shift_up.c ./src/bonus_func.c ./src/checker_ex.c ./src/visual.c ./src/free_struct.c 

SRC_PS = ./src/main.c

SRC_CH = ./src/checker.c

#OBJ_PS = $(patsubst %.c, %.o, $(SRC_SRC)) $(patsubst %.c, %.o, $(SRC_PS))

#OBJ_CH = $(patsubst %.c, %.o, $(SRC_SRC)) $(patsubst %.c, %.o, $(SRC_CH)) 

MLIB = make -C ft_printf

LIB = ft_printf/libftprintf.a

all: $(NAME_CH) $(NAME_PS) 
	
$(NAME_CH): $(SRC_CH) $(SRC_SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC_SRC) $(SRC_CH) $(LIB) -o $(NAME_CH)

$(NAME_PS): $(SRC_PS) $(SRC_SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC_SRC) $(SRC_PS) $(LIB) -o $(NAME_PS)

%.o : %.c
	gcc -c -Wall -Wextra -Werror $<
	
clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH)
	$(MLIB) fclean

re: fclean all