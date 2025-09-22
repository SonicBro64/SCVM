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
    //debug text
    sf::Font font;
	if (!font.loadFromFile("PxPlus_IBM_CGA.ttf")) return -1;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Red);
    
    sf::Texture scrntex;
    if (!scrntex.create(WIDTH, HEIGHT)) return -1;
    sf::Sprite screen(scrntex);
	
	while (window.isOpen()) {
		sf::Event event;
	    while (window.pollEvent(event))
		{
	        if (event.type == sf::Event::Closed) window.close();
	        int AKSize = sizeof(AllowedKeys) / sizeof(AllowedKeys[0]);
	        for (int i=0; i<3; i++) VMkeys[i] = 0;
	        for (int i=0; i<AKSize; i++) {
	        	if (sf::Keyboard::isKeyPressed(AllowedKeys[i]) && VMkeys[0] == 0) {
	        		VMkeys[0] = i+1;
				} else if (sf::Keyboard::isKeyPressed(AllowedKeys[i]) && VMkeys[1] == 0) {
					VMkeys[1] = i+1;
				} else if (sf::Keyboard::isKeyPressed(AllowedKeys[i])){
					VMkeys[2] = i+1;
				}
			}
		}
		window.clear();
		scrntex.update(RGBAFrmBuff);
		//debug Keyboard buffer printout
		text.setString(std::to_string((int)VMkeys[0]) + ", " + std::to_string((int)VMkeys[1]) + ", " + std::to_string((int)VMkeys[2]));
		window.draw(text);
		window.draw(screen);
		window.display();
	}
	return 0;
}
