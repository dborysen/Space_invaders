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

# SRC: main.cpp Hero.cpp Space_invaders.cpp

# INCLUDES: -I Hero.hpp Space_invaders.hpp

all: test

test:
	@echo "compiling..."
	@g++ -Wall -Wextra -Werror -lncurses -std=c++98 -g main.cpp Hero.cpp Space_invaders.cpp Bullet.cpp Enemy.cpp
	@echo "done."
