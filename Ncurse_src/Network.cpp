/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** Network
*/

#include"Network.hpp"

using namespace std;

Network::Network()
{
    setDevice();
    setIp();
    setIncomingFrequ();
    setOutgoingFrequ();
}

void Network::setIncomingFrequ()
{
    struct sysinfo boot;
    sysinfo(&boot);
    setOldTimeIncoming(boot.uptime);
    string cmd = "cat /proc/net/dev | grep "+_device+" > data.txt";
    system(cmd.c_str());
    string byte;
    ifstream file("data.txt", ifstream::in);
    getline(file, byte);
    int i = 1;
    while (byte[i] != ' ')
        i++;
    try {
        byte.erase(i, byte.size());
    } catch (out_of_range &e) {
        byte = "";
    }
    _incoming_bandwidth = byte;
}

void Network::setOutgoingFrequ()
{
    struct sysinfo boot;
    sysinfo(&boot);
    setOldTimeOutgoing(boot.uptime);
    string cmd = "cat /proc/net/dev | grep "+_device+" > data.txt";
    system(cmd.c_str());
    string byte;
    ifstream file("data.txt", std::ifstream::in);
    getline(file, byte);
    int i = 0;
    int count = 0;
    int size = 0;

    while (count != 9) {
        if (byte[i] == ' ') {
            count++;
            while (byte[i] == ' ')
                i++;
            i--;
        }
        i++;
    }
    int tmp = i;
    while (byte[tmp] != ' ') {
        size++;
        tmp++;
    }
    try {
        byte.erase(tmp, byte.size());
        byte.erase(0, i);
    } catch (out_of_range &e) {
        byte = "";
    }
    _outgoing_bandwidth = byte;
}

void Network::setDevice()
{
    system("cat /proc/net/arp  > data.txt" );
    ifstream file("data.txt", ifstream::in);
    string device;
    getline(file, device);
    int pos = device.find("Device");
    getline(file, device);
    try {
        device.erase(0, pos);
    } catch (out_of_range &e)  {
        device = "";
    }
    _device = device;

}

void Network::setIp()
{
    system("cat /proc/net/arp  > data.txt" );
    ifstream file("data.txt", ifstream::in);
    string ip;
    getline(file, ip);
    getline(file, ip);
    int pos2 = ip.find(" ");
    try {
        ip.erase(pos2, ip.size());
    } catch (out_of_range &e) {
        ip = "";
    }
    system("rm data.txt");
    _ip = ip;
}

float Network::calc_sending_speed()
{
    struct sysinfo boot;
    sysinfo(&boot);
    float byte;
    string::size_type s;
    float diff_speed, ob;
    try {
        diff_speed = stof(_outgoing_bandwidth, &s);
        ob = stof(_outgoing_bandwidth, &s);
    } catch (invalid_argument &e) {
        diff_speed = 0;
        ob = 0;
    }
    long long time;
    long long diff_time = _old_time_outgoing;
    getOutgoingByte();
    _old_time_outgoing = boot.uptime;
    byte = ob - diff_speed;
    time = _old_time_outgoing - diff_time;
    return byte/time;
}

float Network::calc_receiving_speed()
{
    struct sysinfo boot;
    sysinfo(&boot);
    float byte;
    string::size_type s;
    float diff_speed, ib;
    try {
        diff_speed = stof(_incoming_bandwidth, &s);
        ib = stof(_incoming_bandwidth, &s);
    } catch (invalid_argument &e) {
        diff_speed = 0;
        ib = 0;
    }
    long long time;
    long long diff_time = _old_time_incoming;
    getIncomingByte();
    _old_time_incoming = boot.uptime;
    byte = ib - diff_speed;
    time = _old_time_incoming - diff_time;
    return byte / time;
}
