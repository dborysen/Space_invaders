// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Space_invaders.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/08 13:18:58 by dborysen          #+#    #+#             //
//   Updated: 2018/06/08 13:18:59 by dborysen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACE_INVADERS_HPP
# define SPACE_INVADERS_HPP

# include <ncurses.h>
# include <iostream>
# include <string>
# include "Hero.hpp"
# include "Enemy.hpp"

class Space_invaders
{
	public:
 		Space_invaders(void);
		Space_invaders(const Space_invaders &other);
		~Space_invaders();

		Space_invaders &operator= (const Space_invaders &other);

		void	startGame(void);

	private:
		WINDOW	*_game_field;
		Hero	*_ship;

		int		_yStart, _xStart;
		char	_shipForm;

		void	_startNcursesMode(void);
		void	_endNcursesMode(void) const;
		void	_makeBox(void);
};

#endif