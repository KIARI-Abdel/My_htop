/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main_display
*/

#ifndef MAIN_DISPLAY_HPP
#define MAIN_DISPLAY_HPP

#include "Basic.hpp"
#include "../Ncurse_src/User.hpp"
#include "../Ncurse_src/Cpu.hpp"
#include "../Ncurse_src/Network.hpp"
#include "../Ncurse_src/Memory.hpp"
#include "Mid/Mid.hpp"
#include "Top/Top.hpp"
#include "Left/Left.hpp"
#include "Right/Right.hpp"

typedef struct {
    Left *left;
    Mid *mid;
    Basic *window;
    Right *right;
    Top *top;
    User *_user;
    Cpu *_cpu;
    Network *_net;
    Memory *_mem;
} block;

void main_display(block *);

#endif //MAIN_DISPLAY_HPP
