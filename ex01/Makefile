NAME	=	411
HDIR	=	.
SDIR	=	.
SRCS	=	$(addprefix $(SDIR)/, 411.cpp Phonebook.cpp Contact.cpp)
CC		=	clang++

all:		$(NAME)

$(NAME):	$(SRCS)
	$(CC) -I$(HDIR) $^ -o $@

re: fclean all

clean:
	@echo "Nothing to clean"

fclean:
	rm -f $(NAME)