#include <SFML/Graphics.hpp>
#include <utility>
#include <cmath>
#include <iostream>

#include "TicTacToe.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tic-tac-toe");
    window.setFramerateLimit(60);

    sf::Vector2i clickPos;
    std::string turn = "X"; 

    std::cout << "biag" << std::endl;

    // game loop
    while (window.isOpen()) {

        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            // close window if close button clicked
            if (event.type == sf::Event::Closed)
                window.close();

            // if LMB is clicked, get the pos, and if it's in a grid, set an X or O into the array
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                clickPos = sf::Mouse::getPosition(window);
                placeXO(clickPos, turn, window);
            }
        }

        // drawing X or O on each grid
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j].XorO == "X") {
                    move(i, j, "X", window);
                }
                else if (arr[i][j].XorO == "O") {
                    move(i, j, "O", window);
                }
            }
        }
       
        // drawing the indicator at the top
        if (turn == "X") {
            drawX({ 350, 25 }, window); 
        }
        else if (turn == "O") {
            drawO({ 350, 25 }, window);
        }

        // drawing the table
        drawTable(window); 

        window.display();

    }

    return 0;
}