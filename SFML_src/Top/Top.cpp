/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** top
*/

#include "Top.hpp"

using namespace std;

const string to_sec(const std::string &str)
{
    string a;
    int i = str.length();
    for (int j = 0; j + i < 10; ++j) {
        a += "0";
    }
    a += str;
    return (a);
}

Top::Top()
{
    if (!this->_font.loadFromFile("font/clacon.ttf"))
        cerr << "Error on Font" << endl;
    /* User */
    this->_user.setFont(this->_font);
    this->_user.setString("USER");
    this->_user.setCharacterSize(TEXT_SIZE);
    this->_user.setPosition(100, 40);
    /* Host */
    this->_host.setFont(this->_font);
    this->_host.setString("Host");
    this->_host.setCharacterSize(TEXT_SIZE);
    this->_host.setPosition(100, 65);
    /* Kernel */
    this->_kernel.setFont(this->_font);
    this->_kernel.setString("Kernel");
    this->_kernel.setCharacterSize(TEXT_SIZE);
    this->_kernel.setPosition(100, 90);
    /* OsName */
    this->_osname.setFont(this->_font);
    this->_osname.setString("OsName");
    this->_osname.setCharacterSize(TEXT_SIZE);
    this->_osname.setPosition(100, 115);
    /* Date & day */
    this->_date.setFont(this->_font);
    this->_date.setString("Sunday 01/20/19");
    this->_date.setCharacterSize(TEXT_SIZE);
    this->_date.setPosition(1640, 40);
    /* Time since boot: */
    this->_time.setFont(this->_font);
    this->_time.setString("Time since last Boot:");
    this->_time.setCharacterSize(TEXT_SIZE);
    this->_time.setPosition(1483, 90);
    /* Hours: */
    this->_hours.setFont(this->_font);
    this->_hours.setString("12:23:28 AM");
    this->_hours.setCharacterSize(TEXT_SIZE);
    this->_hours.setPosition(1674, 65);
    /* Real Time since boot */
    this->_realTime.setFont(this->_font);
    this->_realTime.setString(to_sec("4567890"));
    this->_realTime.setCharacterSize(TEXT_SIZE);
    this->_realTime.setPosition(1684, 90);
}
