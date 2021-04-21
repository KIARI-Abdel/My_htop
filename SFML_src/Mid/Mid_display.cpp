/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** mid_display
*/

#include "Mid_display.hpp"
#include "../../Ncurse_src/Memory.hpp"

using namespace std;

void mid_display(Basic *window, Mid *mid, Memory *_mem)
{
    int percent = 67;
    string ram = "RAM";
    string ramTotal = "Total : ";
    string ramShared = "Shared : ";
    string swap = "SWAP";
    string swapTotal = "Total : ";
    string swapShared = "Shared : ";
    string memory = "Memory Activity : [                              ] ";
    string title = "MEMORY";

    ramTotal += to_string(_mem->getTotalRam());
    ramShared += to_string(_mem->getSharedRam());
    swapTotal += to_string(_mem->getTotalSwap());
    swapShared += to_string(_mem->getFreeSwap());
    memory += to_string(percent);
    memory += "%";

    mid->_ram.setString(ram);
    mid->_ramTotal.setString(ramTotal);
    mid->_ramShared.setString(ramShared);
    mid->_swap.setString(swap);
    mid->_swapTotal.setString(swapTotal);
    mid->_swapShared.setString(swapShared);
    mid->_memoryActiviy.setString(memory);
    mid->_title.setString(title);

    mid->_percentMemory.setSize(sf::Vector2f(250 - ((100 - percent) * 2.5), 5));

    window->_window.draw(mid->_ram);
    window->_window.draw(mid->_ramTotal);
    window->_window.draw(mid->_ramShared);
    window->_window.draw(mid->_swap);
    window->_window.draw(mid->_swapTotal);
    window->_window.draw(mid->_swapShared);
    window->_window.draw(mid->_memoryActiviy);
    window->_window.draw(mid->_title);
    window->_window.draw(mid->_percentMemory);
}
