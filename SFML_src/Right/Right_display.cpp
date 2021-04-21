/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** right_display
*/

#include "Right_display.hpp"
#include "../../Ncurse_src/Network.hpp"

using namespace std;

void right_display(Basic *window, Right *right, Network *_network)
{
    string ipAddress = "IP Address : ";
    string device = "Device : ";
    string incomingBandwidth = "Incoming Bandwidth : ";
    string transmittingBandwidth = "Outgoing Bandwidth : ";
    string title = "NETWORK";

    ipAddress += _network->getIp();
    device += _network->getDevice();
    incomingBandwidth += _network->getIncomingByte();
    transmittingBandwidth += _network->getOutgoingByte();

    right->_ipAddress.setString(ipAddress);
    right->_device.setString(device);
    right->_incomingBandwidth.setString(incomingBandwidth);
    right->_transmittingBandwidth.setString(transmittingBandwidth);
    right->_title.setString(title);

    window->_window.draw(right->_ipAddress);
    window->_window.draw(right->_device);
    window->_window.draw(right->_incomingBandwidth);
    window->_window.draw(right->_transmittingBandwidth);
    window->_window.draw(right->_title);

}
