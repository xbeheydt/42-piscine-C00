# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 13:24:04 by xbeheydt          #+#    #+#              #
#    Updated: 2024/01/18 14:01:00 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re help

NAME 		= libtester
SRCS		=
OBJS		= $(SRCS:.c=.o)

RM			= rm -f

GCC			= gcc
CFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I.
LDFLAGS		=
LNKFLAGS	=
ifdef DEBUG
CFLAGS		+= -g -O0 -DDEBUG
else
CFLAGS		+= -O3
endif


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


all: $(NAME) ## Build libtester

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -c $< -o $@ $(LNKFLAGS)

clean:	## Remove object files
	$(RM) $(OBJS)

fclean: clean ## Remove object files and library
	$(RM) $(NAME)

re: fclean all ## Remove object files and rebuild libtester

help:	## Print help
	@echo "Usage: make [target]"
	@/usr/bin/python3 -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)