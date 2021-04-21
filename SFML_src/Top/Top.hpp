/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** top
*/

#ifndef TOP_HPP
#define TOP_HPP

#include "../Includes.hpp"
#include "../Basic.hpp"

using namespace sf;

class Top {
public:
    Top();

    Text _user;
    Text _host;
    Text _kernel;
    Text _osname;
    Text _date;
    Text _time;
    Text _realTime;
    Text _hours;
    Font _font;
};

void top_display(Basic *window, Top *top);
const std::string to_sec(const std::string &str);

#endif //PISCINE_C_TOP_HPP
