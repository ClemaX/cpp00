NAME	=	megaphone
SRCS	=	megaphone.cpp
CC		=	clang++

all:		$(NAME)

$(NAME):	$(SRCS)
	$(CC) $< -o $@

re: fclean all

clean:
	@echo "Nothing to clean"

fclean:
	rm -f $(NAME)