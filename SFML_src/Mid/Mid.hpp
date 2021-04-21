/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** mid
*/

#ifndef MID_HPP
#define MID_HPP

#include "../Includes.hpp"

using namespace sf;

class Mid {
public:
    Mid();

    Font _font;
    Text _ram;
    Text _ramTotal;
    Text _ramShared;
    Text _swap;
    Text _swapTotal;
    Text _swapShared;
    Text _memoryActiviy;
    Text _title;
    RectangleShape _percentMemory;
};


#endif //MID_HPP
