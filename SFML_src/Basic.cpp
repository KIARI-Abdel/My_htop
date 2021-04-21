/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** basic
*/

#include "Basic.hpp"

using namespace sf;

Basic::Basic()
{
    this->_left = 1;
    this->_top = 1;
    this->_right = 1;
    this->_mid = 1;
    this->_window.create(VideoMode(1920, 1080), "Rush_3");
    this->_window.setFramerateLimit(30);
    this->_clock.Clock::restart();
    if (!this->_backgroundT.loadFromFile("./images/background.png")) {
        std::cerr << "Error loading texture ..." << std::endl;
    }
    this->_backgroundT.setSmooth(true);
    this->_backgroundS.setTexture(this->_backgroundT);

    this->_font.loadFromFile("font/clacon.ttf");

    this->_topT.setFont(this->_font);
    this->_midT.setFont(this->_font);
    this->_rightT.setFont(this->_font);
    this->_leftT.setFont(this->_font);

    this->_topT.setCharacterSize(TEXT_SIZE);
    this->_midT.setCharacterSize(TEXT_SIZE);
    this->_rightT.setCharacterSize(TEXT_SIZE);
    this->_leftT.setCharacterSize(TEXT_SIZE);

    this->_topT.setString("X");
    this->_midT.setString("X");
    this->_rightT.setString("X");
    this->_leftT.setString("X");

    this->_topT.setPosition(1895, 5);
    this->_midT.setPosition(1260, 302);
    this->_rightT.setPosition(1895, 302);
    this->_leftT.setPosition(620, 302);

}
