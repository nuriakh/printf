NAME = libftprintf.a
SRSC =  ft_printf.c ft_functions.c
OBJS = $(SRSC:.a=.o)
CC = cc
INCS = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(INCS)
	@echo "Compiling all object files:"
	$(CC) $(CFLAGS) -c $(SRCS)
	@echo

$(NAME): $(OBJS)
	@echo "Creating archive:" $(NAME)
	ar rc $(NAME) $(OBJS)
	@echo

clean:
	@echo "Removing all object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing" $(NAME)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re