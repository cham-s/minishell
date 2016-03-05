NAME = minishell
CC = clang
LIB = libft/libft.a
FLAGS = -g -Wall -Werror -Wextra
INCLUDES = -I includes -I libft/includes
OBJS = main.o utils.o exec.o env.o cmd.o dictionary.o dictionary2.o split_parse.o \
	   error.o parser.o init.o
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
