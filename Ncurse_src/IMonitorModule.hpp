/*
** EPITECH PROJECT, 2018
** IMONITORMODULE header
** File description:
** header
*/

#ifndef IMONITORMODULE_H
#define IMONITORMODULE_H

#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/utsname.h>
#include <fstream>
#include <numeric>
#include <vector>
#include <time.h>
#include<sys/sysinfo.h>
#include<cstring>

class IMonitorModule 
{
    public:
        virtual ~IMonitorModule() {}
};

#endif //MONITORMODULE_HPP