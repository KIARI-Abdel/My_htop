/*
** EPITECH PROJECT, 2019
** cpp_rush3
** File description:
** header
*/

#ifndef NCURSE_H
#define NCURSE_H

#include <ncurses.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <time.h>

#include"IMonitorDisplay.hpp"

#include "User.hpp"
#include "Cpu.hpp"
#include "Memory.hpp"
#include "Network.hpp"

typedef struct
{
    WINDOW *_headWin;
    WINDOW *_cpuWin;
    WINDOW *_memWin;
    WINDOW *_networkWin;
    bool _cpuActive;
    bool _memActive;
    bool _netActive;
} windows;

class Ncurse :  public IMonitorDisplay
{
    public:
         ~Ncurse() {}
         Ncurse();
        void start() final;
    private:
};


#endif
