// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Space_invaders.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/15 14:32:47 by dborysen          #+#    #+#             //
//   Updated: 2018/06/15 14:32:48 by dborysen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Space_invaders.hpp"

Space_invaders::Space_invaders() : _yStart(0), _xStart(0)
{
	return ;
}

Space_invaders::Space_invaders(const Space_invaders &other)
{
	(*this) = other;
	return ;
}

Space_invaders::~Space_invaders()
{
	return ;
}

void	Space_invaders::startGame()
{
	this->_startNcursesMode();
	
	this->_ship = new Hero(this->_game_field, 11, 20, '}');

	this->_endNcursesMode();
	std::cout << std::endl << "   -GAME OVER-" << std::endl;
	std::cout << "Your Score is: "<< this->_ship->getScore() << std::endl << std::endl;
	delete this->_ship;
}

void	Space_invaders::_startNcursesMode()
{
	initscr();
	noecho();
	cbreak();
	srand(time(NULL));
	curs_set(0);
	timeout(0);
	this->_makeBox();
	return ;
}

void	Space_invaders::_endNcursesMode() const
{
	getch();
	endwin();
	return ;
}

void	Space_invaders::_makeBox()
{
	this->_game_field = newwin(LINES - 1, COLS, 1, 0);
	refresh();
	box(this->_game_field, 0, 0);
	wrefresh(this->_game_field);
	nodelay(this->_game_field, true);
	return ;
}

Space_invaders &Space_invaders::operator= (const Space_invaders &other)
{
	this->_shipForm = other._shipForm;
	this->_yStart = other._yStart;
	this->_xStart = other._xStart;
	if (this->_ship != nullptr)
		delete this->_ship;
	this->_ship = other._ship;
	this->_game_field = other._game_field;
	return (*this);
}