#ifndef SFMLLIB_HPP
# define SFMLLIB_HPP

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "../Game/GUIInterface.hpp"

class Sfmllib : public DynamicGUI {
	private:
		sf::RectangleShape	head;
		sf::RectangleShape	body;
		sf::RectangleShape	food;
		sf::RectangleShape	frame;
		sf::RenderWindow	window;
	public:
		Sfmllib(void);
		virtual ~Sfmllib(void);
		int		userResponse();
		void	printPlayer(std::list<Vector> snakePoints);
		void 	drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score);
};

#endif
