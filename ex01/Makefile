NAME	=	411

IDIR	=	.
SDIR	=	.
ODIR	=	objs
BDIR	=	.

SRCS	=	$(addprefix $(SDIR)/, 411.cpp Phonebook.cpp Contact.cpp Validators.cpp InputField.cpp)
OBJS	=	$(SRCS:$(SDIR)/%.cpp=$(ODIR)/%.o)
DEPS	=	$(OBJS:.o=.d)

CXX		=	clang++
LD		=	clang++

CFLAGS	=	-Wall -Wextra -Werror -I$(IDIR)
DFLAGS	=	-MT $@ -MMD -MP -MF $(ODIR)/$*.d

COMPILE.cpp	=	$(CXX) $(DFLAGS) $(CFLAGS) -c
COMPILE.o	=	$(LD) $(LDFLAGS)

all:		$(BDIR)/$(NAME)

# Directories
$(ODIR) $(BDIR):
	@echo "MK $@"
	mkdir -p "$@"

# Dependencies
$(DEPS): $(ODIR)/%.d:
include $(wildcard $(DEPS))

# Objects
$(OBJS): $(ODIR)/%.o: $(SDIR)/%.cpp $(ODIR)/%.d | $(SDIR)
	@mkdir -p '$(@D)'
	@echo "CXX $<"
	$(COMPILE.cpp) $< -o $@

# Binaries
$(BDIR)/$(NAME):	$(OBJS) | $(BDIR)
	@echo "LD $@"
	$(COMPILE.o) $^ -o $@ $(LDLIBS)

re: fclean all

clean:
	rm -f $(OBJS) $(DEPS)
	@rmdir $(ODIR) || :

fclean: clean
	rm -f $(BDIR)/$(NAME)

.PHONY: re clean fclean

$(VERBOSE).SILENT: