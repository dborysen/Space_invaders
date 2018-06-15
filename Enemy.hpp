// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/11 14:37:57 by dborysen          #+#    #+#             //
//   Updated: 2018/06/11 14:37:58 by dborysen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>
# include <ncurses.h>
# include <ctime>

class Enemy
{
	public:
		Enemy(void);
		Enemy(WINDOW *window, int xMax, int yMax);
		Enemy(const Enemy &other);
		~Enemy();

		Enemy &operator= (const Enemy &other);
		
		void		fly(void);
		const int	&getX(void) const;
		const int	&getY(void) const;
		void		setAsDead(void);

	private:
		WINDOW		*_current_window;
		int			_x, _y;
		int			_xMax, _yMax;

		int			_getRandomCoord(void);
};

#endif