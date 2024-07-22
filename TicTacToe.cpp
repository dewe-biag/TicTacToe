#include <SFML/Graphics.hpp>
#include <utility>
#include <cmath>
#include <iostream> 

#include "TicTacToe.hpp"

const int thickness = 15;
const int shapeWH = 100;

PosAndLetter arr[3][3] = {
    { {{200, 175}, ""}, {{350, 175}, ""}, {{500, 175}, ""} },
    { {{200, 325}, ""}, {{350, 325}, ""}, {{500, 325}, ""} },
    { {{200, 475}, ""}, {{350, 475}, ""}, {{500, 475}, ""} },
};

void drawX(sf::Vector2f pos, sf::RenderWindow& window) {
    // since we are setting position based off of top left, and our origin is in the middle, we are adding 50 to pos
    pos.x += 50; 
    pos.y += 50; 

    // calculating length based on the height / width of the X, which is 100 
    int length = sqrt(2 * (shapeWH * shapeWH));

    // declaration 
    sf::RectangleShape line1(sf::Vector2f(length - thickness, thickness));
    sf::RectangleShape line2(sf::Vector2f(length - thickness, thickness));

    // setting the positions
    line1.setPosition(pos);
    line2.setPosition(pos);

    // setting the origin of the lines to the center
    line1.setOrigin(line1.getSize().x / 2, line1.getSize().y / 2); // line1 
    line1.setRotation(45);

    line2.setOrigin(line2.getSize().x / 2, line2.getSize().y / 2); // line2
    line2.setRotation(135);

    window.draw(line1);
    window.draw(line2);
}

void drawO(sf::Vector2f pos, sf::RenderWindow& window) {
    pos.x += 50;
    pos.y += 50;

    sf::CircleShape circle((shapeWH / 2) - (thickness));
    circle.setOrigin(circle.getRadius(), circle.getRadius());

    circle.setPosition(pos);

    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(thickness);

    window.draw(circle);
}

void drawTable(sf::RenderWindow& window) {
    sf::RectangleShape hBorder1(sf::Vector2f(500, 50));
    hBorder1.setPosition(150, 275);

    sf::RectangleShape hBorder2(sf::Vector2f(500, 50));
    hBorder2.setPosition(150, 425);

    sf::RectangleShape vBorder1(sf::Vector2f(50, 500));
    vBorder1.setPosition(300, 150);

    sf::RectangleShape vBorder2(sf::Vector2f(50, 500)); 
    vBorder2.setPosition(450, 150);

    window.draw(hBorder1);
    window.draw(hBorder2);
    window.draw(vBorder1); 
    window.draw(vBorder2);
}

void move(int x, int y, const std::string XorO, sf::RenderWindow& window) {
    if (XorO == "X")
        drawX(arr[x][y].pos, window);

    if (XorO == "O")
        drawO(arr[x][y].pos, window);
}

void checkWinner() {
    int XHcount = 0, OHcount = 0, XVcount = 0, OVcount = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // check horiz lines
            if (arr[i][j].XorO == "X") {
                XHcount++;
            }
            else if (arr[i][j].XorO == "O") {
                OHcount++;
            }

            // check vert lines
            if (arr[j][i].XorO == "X") {
                XVcount++; 
            } 
            else if (arr[j][i].XorO == "O") {
                OVcount++; 
            }
        }

        if (XHcount == 3) {
            std::cout << "X wins" << std::endl;
        }
        else if (OHcount == 3) {
            std::cout << "O wins" << std::endl;
        }
        else if (XVcount == 3) {
            std::cout << "X wins" << std::endl;
        }
        else if (OVcount == 3) {
            std::cout << "O wins" << std::endl;
        }

        XHcount = 0;
        OHcount = 0;
        XVcount = 0;
        OVcount = 0;
    }

    int XD1count = 0, OD1count = 0, XD2count = 0, OD2count = 0;

    for (int i = 0; i < 3; i++) {
        if (arr[i][i].XorO == "X") {
            XD1count++; 
        }
        else if (arr[i][i].XorO == "O") {
            OD1count++; 
        }

        if (arr[2 - i][i].XorO == "X") {
            XD2count++; 
        } 
        else if (arr[2 - i][i].XorO == "O") {
            OD2count++; 
        }
    }

    if (XD1count == 3 || XD2count == 3) {
        std::cout << "X wins" << std::endl;
    }
    else if (OD1count == 3 || OD2count == 3) {
        std::cout << "O wins" << std::endl;
    }

}

void placeXO(sf::Vector2i clickPos, std::string& turn, sf::RenderWindow& window) {
    // check every tile and if clickpos fulfills it 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sf::IntRect cell1(arr[i][j].pos.x, arr[i][j].pos.y, 100, 100);

            if (cell1.contains(clickPos)) {
                if (arr[i][j].XorO == "") {
                    move(i, j, turn, window);

                    arr[i][j].XorO = turn;

                    if (turn == "X")
                        turn = "O";
                    else if (turn == "O")
                        turn = "X";
                }
            }
        }
    }
    checkWinner();
}