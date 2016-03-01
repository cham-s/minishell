NAME = minishell
CC = clang
LIB = libft/libft.a
FLAGS = -g -Wall -Werror -Wextra
INCLUDES = -I includes -I libft/includes
OBJS = main.o utils.o env.o cmd.o exec.o
.PHONY: all clean fclean re

VPATH = sources/

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C libft/

%.o : %.c 
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
