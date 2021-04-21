/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** Network
*/

#ifndef NETWORK_H
#define NETWORK_H

#include"MonitorModule.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sys/sysinfo.h>

using namespace std;

class Network : public AMonitorModule
{
public:
    Network();
    string getIp() const {return _ip;};
    string getDevice() const {return _device;};
    string getIncomingByte() const {return _incoming_bandwidth;};
    string getOutgoingByte() const {return _outgoing_bandwidth;};
    void setOldTimeIncoming(unsigned long time) {_old_time_incoming = time;};
    void setOldTimeOutgoing(unsigned long time) {_old_time_outgoing = time;};
    void setOutgoingFrequ();
    void setIncomingFrequ();
    void setIp();
    void setDevice();
    float calc_sending_speed();
    float calc_receiving_speed();

private:
    string _incoming_bandwidth;
    string _outgoing_bandwidth;
    string _ip;
    string _device;
    unsigned long _old_time_incoming;
    unsigned long _old_time_outgoing;
};

#endif
