# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 10:24:08 by xbeheydt          #+#    #+#              #
#    Updated: 2024/01/29 11:55:04 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re help prepare debug debug-tests tests
.DEFAULT: all

NAME		= C00

TYPE		= exe # or lib-static or lib-dynamic

SRCS		= ex00/ft_putchar.c \
			  ex01/ft_print_alphabet.c \
			  ex02/ft_print_reverse_alphabet.c #\
			#   ex03/ft_print_numbers.c #\
			#   ex04/ft_is_negative.c #\
			#   ex05/ft_print_comb.c #\
			#   ex06/ft_print_comb2.c #\
			#   ex07/ft_putnbr.c #\
			#   ex08/ft_print_combn.c
OBJS		= $(SRCS:.c=.o)
TESTS		= $(SRCS:.c=.test.out)

TOUCH		= touch
MKDIR		= mkdir -p
RM			= rm -rf
LINTER		= norminette -R CheckForbiddenSourceHeader

GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra
IFLAGS		=
LDFLAGS		=
LNKFLAGS	=
ifdef DEBUG
CFLAGS		+= -g -O0 -DDEBUG
else
# CFLAGS		+= -O3
endif

# Deps  ########################################################################
LIBTESTER	= deps/libtester/libtester.a
IFLAGS		+= -Ideps/libtester
LDFLAGS     += -Ldeps/libtester
LNKFLAGS	+= -ltester
$(LIBTESTER): ## Compile libtester
	$(MAKE) -C deps/libtester

# Defines how to print help ####################################################
define PRINT_HELP_PYSCRIPT
import re, sys

for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("\t%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT


all: $(NAME) ## Compile all
$(NAME): $(OBJS)


tests: $(LIBTESTER) $(TESTS) ## Compile all and Run tests
# ifndef DEBUG
ifneq ($(EX),)
	./$(wildcard ex${EX}/*.test.out)
else
	$(foreach test, $(TESTS), ./$(test);)
endif
# endif

%.o: %.c
	$(GCC) ${CFLAGS} ${IFLAGS} ${LDFLAGS} -c $< -o $@ ${LNKFLAGS}

%.test.out: %.c
	$(GCC) ${CFLAGS} ${IFLAGS} ${LDFLAGS} -o $@ $(subst .c,.test.c,$<) $< ${LNKFLAGS}


# Common utilitary recipes #####################################################
clean: ## Remove object files
	$(RM) ${OBJS}
	$(RM) ${TESTS}
	$(MAKE) -C deps/libtester clean

fclean: clean ## Remove object and executable files
	$(RM) ${NAME}
	$(MAKE) -C deps/libtester fclean

re: fclean all ## Re-compile
	$(MAKE) -C deps/libtester re

prepare: ## Prepare repository and this structure
	$(foreach src, $(SRCS), $(MKDIR) $(dir $(src)); $(TOUCH) $(src);)
	$(foreach test, $(SRCS), $(TOUCH) $(subst .c,.test.c,$(test));)

help: ## Print helps
	@echo "Usage: make [target]"
	@/usr/bin/python3 -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

lint: ## Check format errors
	$(GCC) ${CFLAGS} ${IFLAGS} ${LDFLAGS} -fsyntax-only ${SRCS} ${LNKFLAGS}
	$(LINTER) $(SRCS)


# Deps  ########################################################################
