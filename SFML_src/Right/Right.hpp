/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** right
*/

#ifndef RIGHT_HPP
#define RIGHT_HPP

#include "../Includes.hpp"

using namespace sf;

class Right {
public:
    Right();

    Font _font;
    Text _ipAddress;
    Text _device;
    Text _incomingBandwidth;
    Text _transmittingBandwidth;
    Text _title;
};

#endif //RIGHT_HPP
