/*
** EPITECH PROJECT, 2019
** cpp_rush3
** File description:
** MonitorModule
*/

#ifndef MONITORMODULE_HPP
#define MONITORMODULE_HPP

#include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
public:
    virtual ~AMonitorModule() {}
    bool isActive;
};

#endif //MONITORMODULE_HPP
