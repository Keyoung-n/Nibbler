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
		sf::RenderWindow		window;

	public:
		Sfmllib(void);
		Sfmllib(Sfmllib const &);
		Sfmllib& operator=(Sfmllib const &);
		virtual ~Sfmllib(void);
		int		userResponse();
		sf::RectangleShape	get_body();
		sf::RectangleShape	get_food();
		sf::RectangleShape	get_frame();
		sf::RectangleShape	get_head();
		void	printPlayer(std::list<Vector> snakePoints);
		void 	drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score);
		void set_body(sf::RectangleShape);
		void set_food(sf::RectangleShape);
		void set_frame(sf::RectangleShape);
		void set_head(sf::RectangleShape);
};

std::ostream & operator<<(std::ostream &, Sfmllib const &);
#endif
