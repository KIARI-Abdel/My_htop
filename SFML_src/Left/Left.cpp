/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** left
*/

#include "Left.hpp"

using namespace std;

Left::Left()
{
    this->nb_of_core = 5;
    if (!this->_font.loadFromFile("font/clacon.ttf"))
            cerr << "Error on Font" << endl;

    this->_CPU.setFont(this->_font);
    this->_nbcore.setFont(this->_font);
    this->_nbproc.setFont(this->_font);
    this->_modname.setFont(this->_font);
    this->_freq.setFont(this->_font);
    this->_cpu0.setFont(this->_font);
    this->_cpu1.setFont(this->_font);
    this->_cpu2.setFont(this->_font);
    this->_cpu3.setFont(this->_font);
    this->_cpu4.setFont(this->_font);

    this->_CPU.setCharacterSize(31);
    this->_nbcore.setCharacterSize(TEXT_SIZE);
    this->_nbproc.setCharacterSize(TEXT_SIZE);
    this->_modname.setCharacterSize(TEXT_SIZE);
    this->_freq.setCharacterSize(TEXT_SIZE);
    this->_cpu0.setCharacterSize(TEXT_SIZE);
    this->_cpu1.setCharacterSize(TEXT_SIZE);
    this->_cpu2.setCharacterSize(TEXT_SIZE);
    this->_cpu3.setCharacterSize(TEXT_SIZE);
    this->_cpu4.setCharacterSize(TEXT_SIZE);

    this->_CPU.setPosition(320, 320);
    this->_modname.setPosition(50, 400);
    this->_nbcore.setPosition(50, 440);
    this->_nbproc.setPosition(50, 480);
    this->_freq.setPosition(50, 520);
    this->_cpu0.setPosition(50, 620);
    this->_cpu1.setPosition(50, 660);
    this->_cpu2.setPosition(50, 700);
    this->_cpu3.setPosition(50, 740);
    this->_cpu4.setPosition(50, 780);
    this->_percentCpu0.setPosition(150, 635);
    this->_percentCpu1.setPosition(150, 675);
    this->_percentCpu2.setPosition(150, 715);
    this->_percentCpu3.setPosition(150, 755);
    this->_percentCpu4.setPosition(150, 795);
    this->_percentFrequancy.setPosition(185, 535);
}
