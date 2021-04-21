/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** basic
*/

#ifndef BASIC_HPP
#define BASIC_HPP

#include "Includes.hpp"

using namespace sf;

class Basic {
public:
    Basic();
    RenderWindow _window;
    Texture _backgroundT;
    Sprite _backgroundS;
    Mouse _mouse;
    bool _top;
    bool _right;
    bool _left;
    bool _mid;
    Font _font;
    Text _topT;
    Text _midT;
    Text _leftT;
    Text _rightT;
    Clock _clock;
};

#endif //BASIC_HPP
