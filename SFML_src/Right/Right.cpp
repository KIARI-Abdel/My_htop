/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** righ
*/

#include "Right.hpp"

Right::Right()
{
    this->_font.loadFromFile("font/clacon.ttf");
    
    this->_ipAddress.setFont(this->_font);
    this->_device.setFont(this->_font);
    this->_incomingBandwidth.setFont(this->_font);
    this->_transmittingBandwidth.setFont(this->_font);
    this->_title.setFont(this->_font);

    this->_ipAddress.setCharacterSize(TEXT_SIZE);
    this->_device.setCharacterSize(TEXT_SIZE);
    this->_incomingBandwidth.setCharacterSize(TEXT_SIZE);
    this->_transmittingBandwidth.setCharacterSize(TEXT_SIZE);
    this->_title.setCharacterSize(31);

    this->_ipAddress.setPosition(1330, 400);
    this->_device.setPosition(1330, 440);
    this->_incomingBandwidth.setPosition(1330, 520);
    this->_transmittingBandwidth.setPosition(1330, 480);
    this->_title.setPosition(1560, 320);
}
