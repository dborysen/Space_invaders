// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Hero.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dborysen <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/05 11:55:46 by dborysen          #+#    #+#             //
//   Updated: 2018/06/05 11:55:47 by dborysen         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HERO_HPP
# define HERO_HPP
# define SPACE			32
# define ESC			27
# define GAME_SPEED		15000
# define ENEMY_COUNT	10

# include <iostream>
# include <string>
# include <ncurses.h>
# include <ctime>
# include <cstdlib>
# include <unistd.h>
# include "Bullet.hpp"
# include "Enemy.hpp"

class Hero
{
	typedef struct	s_bullet
	{
		Bullet 			*newOne;
		struct s_bullet	*next;
	}				t_bullet;

	typedef struct	s_enemy
	{
		Enemy 			*newOne;
		struct s_enemy	*next;
	}				t_enemy;

	public:
		Hero(void);
		Hero(WINDOW *window, int y, int x, char c);
		Hero(const Hero &other);
		~Hero();

		Hero &operator= (const Hero &other);

	private:
		int			_yHero, _xHero;
		int			_yMax, _xMax;
		char		_hero;
		t_bullet	*_magazine;
		t_enemy		*_enemies;
		WINDOW		*_current_window;

		void		_shoot();
		void		_moveUp();
		void		_moveDown();
		void		_moveLeft();
		void		_moveRight();
		int			_getMove();
		void		_showHeroPosition() const;
		void		_moveAllBullets();
		void		_freeBulletList();
		void		_controlTheShip();
		int			_countEnemies() const;
		void		_addNewEnemy();
		void		_moveAllEnemies();
		void		_checkHitting();
		void		_freeEnemyList();
		bool		_heroAlive() const;
};

#endif