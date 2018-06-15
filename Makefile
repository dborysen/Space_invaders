#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 10:56:40 by dborysen          #+#    #+#              #
#    Updated: 2018/06/05 10:56:41 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# all: test

# test:
# 	@echo "compiling..."
# 	@g++ -Wall -Wextra -Werror -lncurses -std=c++98 -g main.cpp Hero.cpp Space_invaders.cpp Bullet.cpp Enemy.cpp
# 	@echo "done."

NAME = play

SRCS =  main.cpp Hero.cpp Space_invaders.cpp Bullet.cpp Enemy.cpp

OBJECT = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

%.o	: %.cpp
		@gcc $(FLAGS) -c $< -o $@
		@echo "\033[1mASM :\033[0m		 \033[37m[Compilation:\033[0m\033[36m $@\033[0m]"

all: $(NAME)

$(NAME): $(OBJECT)
	@gcc $(FLAGS) $(SRCS) -o ./$(NAME)
	@echo "\033[5;32m--------------------------\033[0m"
	@echo "\033[5;32m         ASM - OK         \033[0m"
	@echo "\033[5;32m--------------------------\033[0m"

clean:
	@rm -f $(OBJECT) *.o
	@echo "\033[32m[.o files has been deleted]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32m[asm binary has been deleted]\033[0m"

re: fclean all