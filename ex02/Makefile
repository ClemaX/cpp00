NAME	=	tests
HDIR	=	.
SDIR	=	.
SRCS	=	$(addprefix $(SDIR)/, tests.cpp Account.class.cpp)
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror
TRUTH	=	19920104_091532.log
OUTPUT	=	my.log

all:		$(NAME)

$(NAME):	$(SRCS)
	$(CC) $(CFLAGS) -I$(HDIR) $^ -o $@

re: fclean all

clean:
	rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)

test: all
	./$(NAME) | cut -c18- > $(OUTPUT)
	cut -c18- $(TRUTH) | diff $(OUTPUT) -
	