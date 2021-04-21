/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** mid
*/

#include "Mid.hpp"

Mid::Mid()
{
    this->_font.loadFromFile("font/clacon.ttf");

    this->_ram.setFont(this->_font);
    this->_ramTotal.setFont(this->_font);
    this->_ramShared.setFont(this->_font);
    this->_swap.setFont(this->_font);
    this->_swapShared.setFont(this->_font);
    this->_swapTotal.setFont(this->_font);
    this->_memoryActiviy.setFont(this->_font);
    this->_title.setFont(this->_font);

    this->_ram.setCharacterSize(TEXT_SIZE);
    this->_ramTotal.setCharacterSize(TEXT_SIZE);
    this->_ramShared.setCharacterSize(TEXT_SIZE);
    this->_swap.setCharacterSize(TEXT_SIZE);
    this->_swapTotal.setCharacterSize(TEXT_SIZE);
    this->_swapShared.setCharacterSize(TEXT_SIZE);
    this->_memoryActiviy.setCharacterSize(TEXT_SIZE);
    this->_title.setCharacterSize(31);

    this->_ram.setPosition(690, 400);
    this->_ramTotal.setPosition(710, 440);
    this->_ramShared.setPosition(710, 480);
    this->_swap.setPosition(690, 520);
    this->_swapTotal.setPosition(710, 560);
    this->_swapShared.setPosition(710, 600);
    this->_memoryActiviy.setPosition(690, 660);
    this->_title.setPosition(930, 320);
    this->_percentMemory.setPosition(880, 675);
}
