/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** sfml
*/

#ifndef SFML_HPP
#define SFML_HPP

#include"IMonitorDisplay.hpp"

class Sfml : public IMonitorDisplay
{
    public:
        inline ~Sfml() {}
        void start() final;

    private:
};


#endif // SFML_HPP
