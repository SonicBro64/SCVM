#include <SFML/Graphics.hpp>
#include <cstdint>
typedef uint8_t Byte;
#include "VMkeys.hpp"

#define WIDTH  640
#define HEIGHT 480

sf::Uint8 RGBAFrmBuff[WIDTH * HEIGHT * 4];
Byte PalFrmBuff[(WIDTH / 2) * HEIGHT];

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    sf::Texture scrntex;
    if (!scrntex.create(WIDTH, HEIGHT)) return -1;
    sf::Sprite screen(scrntex);
	
	while (window.isOpen()) {
		sf::Event event;
	    while (window.pollEvent(event))
		{
	        if (event.type == sf::Event::Closed) window.close();
	        int AKSize = sizeof(AllowedKeys) / sizeof(AllowedKeys[0]);
	        for (int i=1; i<=AKSize; i++)
				if (sf::Keyboard::isKeyPressed(AllowedKeys[i])) VMkeys[0] = i;
		}
		window.clear();
		scrntex.update(RGBAFrmBuff);
		window.draw(screen);
		window.display();
	}
	return 0;
}
