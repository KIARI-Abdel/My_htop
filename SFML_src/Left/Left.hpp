/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** left
*/

#ifndef LEFT_HPP
#define LEFT_HPP

#include "../Includes.hpp"
#include "../Basic.hpp"

using namespace sf;

class Left {
    public:
    Left();
    Text _CPU;
    Text _nbcore;
    Text _nbproc;
    Text _modname;
    Text _freq;
    Text _cpu0;
    Text _cpu1;
    Text _cpu2;
    Text _cpu3;
    Text _cpu4;
    Font _font;
    RectangleShape _percentFrequancy;
    RectangleShape _percentCpu0;
    RectangleShape _percentCpu1;
    RectangleShape _percentCpu2;
    RectangleShape _percentCpu3;
    RectangleShape _percentCpu4;
    int nb_of_core;
};

void left_display(Basic *window, Left *left);

#endif //LEFT_HPP
