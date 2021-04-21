/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** Memory
*/

#include "Memory.hpp"

Memory::Memory()
{
    struct sysinfo info;
    sysinfo(&info);

    _total_ram = info.totalram;
    _total_swap = info.totalswap;
    _free_swap = info.freeswap;
    _shared_ram = info.sharedram;
}
