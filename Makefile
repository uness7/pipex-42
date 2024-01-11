CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

CFILES = pipex.c \
		 pipex_utils.c \
		 run_cmd1.c \
		 run_cmd2.c \
		 pipex_utils2.c \
		 pipex_utils3.c \
		 errors.c \
		 free_pipex.c \
		 ft_split.c \

OBJECTS=$(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
