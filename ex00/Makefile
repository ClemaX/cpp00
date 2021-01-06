NAME	=	megaphone
SRCS	=	megaphone.cpp
CXX		=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

all:		$(NAME)

$(NAME):	$(SRCS)
	$(CXX) $(CFLAGS) $< -o $@

re: fclean all

clean:
	@echo "Nothing to clean"

fclean:
	rm -f $(NAME)
