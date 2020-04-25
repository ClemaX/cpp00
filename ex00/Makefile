NAME	=	megaphone
SRCS	=	megaphone.cpp
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRCS)
	$(CC) $(CFLAGS) $< -o $@

re: fclean all

clean:
	@echo "Nothing to clean"

fclean:
	rm -f $(NAME)