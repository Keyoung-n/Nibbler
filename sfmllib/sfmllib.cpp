#include "sfmllib.hpp"

Sfmllib::Sfmllib(void) : window(sf::VideoMode(640, 480), "snake")
{
}

Sfmllib::~Sfmllib(void)
{

}

int		Sfmllib::userResponse()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			return (1);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			return (2);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			return (3);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return (4);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return (-1);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			return (5);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			return (6);
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			return (7);
	}
	return (0);
}

void	Sfmllib::printPlayer(std::list<Vector> snakePoints)
{
	head.setSize(sf::Vector2f(10,10));
	head.setOutlineColor(sf::Color::Red);
	head.setOutlineThickness(2);

	body.setSize(sf::Vector2f(10,10));
	body.setOutlineColor(sf::Color::Cyan);
	body.setOutlineThickness(2);

	std::list<Vector>::iterator next;
	for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
			next = point;
			next++;

		if (next != snakePoints.end()) {
					if (next->x > point->x) {
							for (int x = point->x; x != next->x; x++)
							{
									body.setPosition(((x + 1) << 3) + ((x + 1) << 1),((point->y + 1) << 3) + ((point->y + 1) << 1));
									window.draw(body);
							}
					}
					else if (next->x < point->x) {
							for (int x = next->x; x != point->x; x++)
							{
									body.setPosition(((x + 1) << 3) + ((x + 1) << 1),((point->y + 1) << 3) + ((point->y + 1) << 1));
									window.draw(body);
							}
					}
					else if (next->y > point->y) {
							for (int y = point->y; y != next->y; y++)
							{
									body.setPosition(((point->x + 1) << 3) + ((point->x + 1) << 1),((y + 2) << 3) + ((y + 2) << 1));
									window.draw(body);
							}
					}
					else if (next->y < point->y) {
							for (int y = next->y; y != point->y; y++)
							{
									body.setPosition(((point->x + 1) << 3) + ((point->x + 1) << 1),((y + 1) << 3) + ((y + 1) << 1));
									window.draw(body);
							}
					}
			}
			else {
					head.setPosition((((point->x + 1) << 3) + ((point->x + 1) << 1)),(((point->y + 1) << 3) + ((point->y + 1) << 1)));
					window.draw(head);
			}
	}
}

void 	Sfmllib::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int)
{
		int y = ((mapsize.y + 2) << 3) + ((mapsize.y + 2) << 1);
		int x = ((mapsize.x + 2) << 3) + ((mapsize.x + 2) << 1);
		frame.setSize(sf::Vector2f(7,7));
		frame.setOutlineColor(sf::Color::Blue);
		frame.setOutlineThickness(2);

		food.setSize(sf::Vector2f(10,10));
		food.setOutlineColor(sf::Color::Green);
		food.setOutlineThickness(2);

		window.clear();
		for (int i = 0; i != x + 1; i++) {
				frame.setPosition(i, 0);
				window.draw(frame);
				frame.setPosition(i, y);
				window.draw(frame);
		}
		for (int i = 0; i != y; i++) {
				frame.setPosition(0, i);
				window.draw(frame);
				frame.setPosition(x, i);
				window.draw(frame);
		}
		for (std::list<Vector>::iterator apple = apples.begin(); apple != apples.end() ; ++apple) {
				food.setPosition((((apple->x + 1) << 3) + ((apple->x + 1) << 1)),(((apple->y + 1) << 3) + ((apple->y + 1) << 1)));
				window.draw(food);
		}
		printPlayer(playerCords);
		window.display();

}

extern "C" Sfmllib *create_gl() {
		Sfmllib *lib = new Sfmllib;
		return (lib);
}

extern "C" void destroy_gl(Sfmllib *lib) {
		delete lib;
}

// Canonical stuff

Sfmllib::Sfmllib(Sfmllib const & copy) {
	*this = copy;
}

Sfmllib& Sfmllib::operator=(Sfmllib const & copy) {
	if ( this != &copy ) {
 		Sfmllib new_gui(copy);
		set_body(new_gui.get_body());
		set_food(new_gui.get_food());
		set_frame(new_gui.get_frame());
		set_head(new_gui.get_head());
	}
	return *this;
}

sf::RectangleShape	Sfmllib::get_body() 		{ return body; }
sf::RectangleShape	Sfmllib::get_food() 		{ return food; }
sf::RectangleShape	Sfmllib::get_frame()		{ return frame; }
sf::RectangleShape	Sfmllib::get_head()			{ return head; }

void Sfmllib::set_body(sf::RectangleShape new_body)		{ body = new_body; }
void Sfmllib::set_food(sf::RectangleShape new_food)		{ food = new_food; }
void Sfmllib::set_frame(sf::RectangleShape new_frame)	{ frame = new_frame; }
void Sfmllib::set_head(sf::RectangleShape new_head)		{ head = new_head; }
