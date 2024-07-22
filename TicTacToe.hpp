#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <SFML/Graphics.hpp>

struct PosAndLetter {
    sf::Vector2f pos;
    std::string XorO;
};
extern PosAndLetter arr[3][3]; 

void drawX(const sf::Vector2f pos, sf::RenderWindow& window);
void drawO(const sf::Vector2f pos, sf::RenderWindow& window);
void drawTable(sf::RenderWindow& window);
void move(int x, int y, const std::string XorO, sf::RenderWindow& window); 
void checkWinner();
void placeXO(sf::Vector2i clickPos, std::string& turn, sf::RenderWindow& window);

#endif