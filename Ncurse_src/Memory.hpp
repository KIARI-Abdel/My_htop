/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** Memory
*/

#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "MonitorModule.hpp"

class Memory : public AMonitorModule
{
public:
    Memory();
    ~Memory() = default;
    unsigned long getTotalRam() const {return _total_ram;};
    unsigned long getTotalSwap() const {return _shared_ram;};
    unsigned long getFreeSwap() const {return _free_swap;};
    unsigned long getSharedRam() const {return _shared_ram;};

private:
    unsigned long _total_ram;
    unsigned long _total_swap;
    unsigned long _free_swap;
    unsigned long _shared_ram;
};


#endif //MEMORY_HPP
