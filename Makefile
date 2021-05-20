SHELL =		/bin/sh
NAME =		push_swap

.SUFFIXES =	.c .o .h

SRCDIR =	src
INCDIR =	inc
LIBDIR =	lib
OBJDIR =	.obj

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			$(addprefix exception/,\
			bad_alloc\
			exception_handler\
			invalid_arguments)\
			$(addprefix operations/,\
			push\
			reverse_rotate\
			rotate\
			swap)\
			parser/parser\
			main)
INC =		$(addsuffix $(word 3, $(.SUFFIXES)),\
			libft\
			list\
			push_swap)
LIB =		ft\
			list
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 2, $(.SUFFIXES)))

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -I $(INCDIR)
LCFLAGS =	$(addprefix -L, $(LIBDIR)) $(addprefix -l, $(LIB))

####    COLORS    ####
KNRM =		\x1B[0m
KRED =		\x1B[31m
KGRN =		\x1B[32m
KYEL =		\x1B[33m
KBLU =		\x1B[34m
KMAG =		\x1B[35m
KCYN =		\x1B[36m
KWHT =		\x1B[37m
######################

all: $(OBJDIR) $(foreach i, $(LIB), $(LIBDIR)/lib$(i).a) $(NAME)
	@printf "$(KGRN)\`$(NAME)\` is up to date.\n"

$(LIBDIR)/libft.a:
	@printf "$(KMAG)➤ "
	make -C $(LIBDIR)/libft_ultimate
	@printf "$(KYEL)➤ "
	cp $(LIBDIR)/libft_ultimate/libft.a $(LIBDIR)

$(LIBDIR)/liblist.a:
	@printf "$(KMAG)➤ "
	make -C $(LIBDIR)/liblist_ultimate
	@printf "$(KYEL)➤ "
	cp $(LIBDIR)/liblist_ultimate/liblist.a $(LIBDIR)

$(OBJDIR):
	@printf "$(KYEL)➤ "
	mkdir $@
	@printf "➤ "
	mkdir $@/exception
	@printf "➤ "
	mkdir $@/operations
	@printf "➤ "
	mkdir $@/parser
	@printf "$(KNRM)"

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@printf "$(KCYN)[  Linking  ]\n➤ "
	$(CC) $(CFLAGS) $^ -o $@ $(LCFLAGS)
	@printf "$(KNRM)"

$(OBJDIR)/%$(word 2, $(.SUFFIXES)): $(SRCDIR)/%$(word 1, $(.SUFFIXES))
	@printf "$(KMAG)[  Compiling  ]\n➤ "
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(KNRM)"

clean:
	@printf "$(KRED)➤ "
	rm -rf $(OBJDIR)
	@printf "$(KNRM)"

fclean: clean
	@printf "$(KRED)➤ "
	rm -f $(NAME) $(foreach i, $(LIB), $(LIBDIR)/lib$(i).a)
	@printf "➤ "
	make -C $(LIBDIR)/libft_ultimate fclean
	@printf "$(KRED)➤ "
	make -C $(LIBDIR)/liblist_ultimate fclean
	@printf "$(KNRM)"

re: fclean all
