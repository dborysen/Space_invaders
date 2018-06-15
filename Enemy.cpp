// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/15 17:09:44 by dborysen          #+#    #+#             //
//   Updated: 2018/06/15 17:09:45 by dborysen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy()
{
	return ;
}

Enemy::Enemy(WINDOW *win, int xMax, int yMax)
{
	this->_current_window = win;
	this->_xMax = xMax;
	this->_yMax = yMax;
	this->_x = this->_xMax - 4;
	this->_y = this->_getRandomCoord();
	if (this->_y == 0)
		this->_y = 1;
	mvwaddch(this->_current_window, this->_y, this->_x, '<');
	return ;
}

Enemy::Enemy(const Enemy &other) : _xMax(0), _yMax(0)
{
	*this = other;
	return ;
}

Enemy::~Enemy()
{
	return ;
}

void	Enemy::setAsDead(void)
{
	mvwaddch(this->_current_window, this->_y, this->_x + 1, ' ');
	this->_x = this->_xMax - 4;
	this->_y = this->_getRandomCoord();
	if (this->_y == 0)
		this->_y = 1;
	return ; 
}

const int	&Enemy::getX(void) const
{
	return (this->_x);
}

const int	&Enemy::getY(void) const
{
	return (this->_y);
}

void		Enemy::fly(void)
{
	if (this->_x > 1)
	{
		mvwaddch(this->_current_window, this->_y, this->_x, '<');
		mvwaddch(this->_current_window, this->_y, this->_x + 1, ' ');
		this->_x--;	
	}
	else if (this->_x == 1)
	{
		mvwaddch(this->_current_window, this->_y, this->_x + 1, ' ');
		this->_x = this->_xMax - 4;
		this->_y = this->_getRandomCoord();
		if (this->_y == 0)
			this->_y = 1;
	}
}

int			Enemy::_getRandomCoord(void)
{
	return (rand() % LINES - 1);
}

Enemy &Enemy::operator= (const Enemy &other)
{
	this->_current_window = other._current_window;
	this->_x = other._x;
	this->_y = other._y;
	this->_xMax = other._xMax;
	this->_yMax = other._yMax;
	return (*this);
}