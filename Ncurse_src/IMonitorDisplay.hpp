/*
** EPITECH PROJECT, 2018
** IMONITORDISPLAY header
** File description:
** header
*/

#ifndef IMONITORDISPLAY_H
#define IMONITORDISPLAY_H

class IMonitorDisplay 
{
    public:
        virtual ~IMonitorDisplay() {};
        virtual void start() = 0;
    private:
};

#endif