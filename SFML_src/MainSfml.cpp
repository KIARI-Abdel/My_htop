/*
** EPITECH PROJECT, 2018
** cpp_rush3
** File description:
** main_sfml
*/

#include "Includes.hpp"
#include "Basic.hpp"
#include "Main_display.hpp"
#include "../Ncurse_src/Sfml.hpp"
#include "Right/Right.hpp"
#include "Mid/Mid.hpp"
#include "Left/Left.hpp"
#include "Top/Top.hpp"

using namespace sf;

void check_mouse(Basic *window)
{
    int x = window->_mouse.getPosition().x;
    int y = window->_mouse.getPosition().y;

    if (x > 1890 && x < 1920 && y > 60 && y < 95)
        window->_top = !window->_top;
    if (x > 615 && x < 635 && y > 360 && y < 395)
        window->_left = !window->_left;
    if (x > 1255 && x < 1280 && y > 360 && y < 395)
        window->_mid = !window->_mid;
    if (x > 1890 && x < 1920 && y > 360 && y < 395)
        window->_right = !window->_right;
}

void Sfml::start()
{
    block container;
    container.left = new Left;
    container.mid = new Mid;
    container.window = new Basic;
    container.right = new Right;
    container.top = new Top;
    container._cpu = new Cpu;
    container._net = new Network;
    container._mem = new Memory;
    container._user = new User;

    while (container.window->_window.isOpen())
    {
        Event event;
        while (container.window->_window.pollEvent(event)) {
            if (event.type == Event::MouseButtonPressed)
                check_mouse(container.window);
            if (event.type == Event::Closed)
                container.window->_window.close();
        }
        Time time = container.window->_clock.getElapsedTime();
        if (time.asSeconds() > 0.1) {
            container.window->_window.clear(WINDOW_COLOR);
            main_display(&container);
            container.window->_clock.Clock::restart();
            container.window->_window.display();
        }
    }
}
