/*
** EPITECH PROJECT, 2019
** cpp_rush3
** File description:
** User
*/

#include"User.hpp"

using namespace std;

User::User()
{
    struct utsname info;
    struct sysinfo boot;
    char tmp[_POSIX_HOST_NAME_MAX];
    sysinfo(&boot);
    if (!uname(&info)) {
        _kernel_version = info.version;
        _os_name = info.sysname;
    }
    _boot_time = boot.uptime;
    gethostname(tmp, _POSIX_HOST_NAME_MAX);
    _hostName = string(tmp);
    getlogin_r(tmp, _POSIX_LOGIN_NAME_MAX);
    _userName = string(tmp);
}

unsigned long User::getUpTime() const
{
    return _boot_time;
}

string User::getOs() const
{
    return _os_name;
}

string User::getKernel() const
{
    return _kernel_version;
}

string User::getHostName() const
{
    return _hostName;
}

string User::getUserName() const
{
    return _userName;
}

string User::getDate() const
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%A %D", timeinfo);
    return string(buffer);
}

string User::getTime() const
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%r", timeinfo);
    return string(buffer);
}