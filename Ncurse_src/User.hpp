/*
** EPITECH PROJECT, 2019
** cpp_rush3
** File description:
** header
*/

#ifndef USER_HPP
#define USER_HPP

#include"IMonitorModule.hpp"

using namespace std;

class User 
{
public:
    User();
    unsigned long getUpTime() const;
    string getOs() const;
    string getKernel() const;
    string getUserName() const;
    string getHostName() const;
    string getDate() const;
    string getTime() const;

private:
    unsigned long _boot_time;
    string _os_name;
    string _kernel_version;
    string _userName;
    string _hostName;
};

#endif // USER_HPP
