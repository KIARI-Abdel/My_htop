/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** top_display
*/

#include "Top_display.hpp"
#include "../../Ncurse_src/User.hpp"

void top_display(Basic *window, Top *top, User *_user)
{
    top->_user.setString("User Name : " + _user->getUserName());
    top->_host.setString("Host Name : " + _user->getHostName());
    top->_kernel.setString("Kernel Version : " + _user->getKernel());
    top->_osname.setString("Operating System : " + _user->getOs());
    top->_date.setString(_user->getDate());
    top->_hours.setString(_user->getTime());
    top->_realTime.setString(to_sec(std::to_string(_user->getUpTime())));
    window->_window.draw(top->_user);
    window->_window.draw(top->_host);
    window->_window.draw(top->_kernel);
    window->_window.draw(top->_osname);
    window->_window.draw(top->_date);
    window->_window.draw(top->_time);
    window->_window.draw(top->_hours);
    window->_window.draw(top->_realTime);
}
