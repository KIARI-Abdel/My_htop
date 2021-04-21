/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** left_display
*/

#include "Left_display.hpp"
#include "../../Ncurse_src/Cpu.hpp"
#include <iterator>

using namespace std;

void left_display(Basic *window, Left *left, Cpu *_cpu)
{
    int percent = 33;
    int percent0 = 67;
    int percent1 = 12;
    int percent2 = 34;
    int percent3 = 23;
    int percent4 = 43;

    /*std::vector<int> percent;
    std::vector<int> percent0;
    std::vector<int> percent1;
    std::vector<int> percent2;
    std::vector<int> percent3;
    std::vector<int> percent4;*/

    /*std::vector<int> percentAll = _cpu->getActivity();
    for (int i = 0; i < percentAll.end(); i++) {
        if (i == 0)
            percent = percentAll[i];
        if (i == 1)
            percent0 = percentAll[i];
        if (i == 2)
            percent1 = percentAll[i];
        if (i == 3)
            percent2 = percentAll[i];
        if (i == 4)
            percent3 = percentAll[i];
        if (i == 5)
            percent4 = percentAll[i];
    }

    //percent.begin();*/

    string cpu = "CPU";
    string nbCore = "Number of Cores : ";
    string nbProc = "Number of Processus : ";
    string modName = "Name : ";
    string freq = "Frequency : [                              ] ";
    string cpu0 = "Cpu 0 => [                              ] ";
    string cpu1 = "Cpu 1 => [                              ] ";
    string cpu2 = "Cpu 2 => [                              ] ";
    string cpu3 = "Cpu 3 => [                              ] ";
    string cpu4 = "Cpu 4 => [                              ] ";

    left->nb_of_core = std::stoi(_cpu->getNbCore()) -1;
    nbCore += std::to_string(left->nb_of_core);
    nbProc += _cpu->getProcs();
    modName += _cpu->getCpuName();
    freq += to_string(percent);
    freq += "%";
    cpu0 += to_string(percent0);
    cpu0 += "%";
    cpu1 += to_string(percent1);
    cpu1 += "%";
    cpu2 += to_string(percent2);
    cpu2 += "%";
    cpu3 += to_string(percent3);
    cpu3 += "%";
    cpu4 += to_string(percent4);
    cpu4 += "%";

    left->_CPU.setString(cpu);
    left->_nbcore.setString(nbCore);
    left->_nbproc.setString(nbProc);
    left->_modname.setString(modName);
    left->_freq.setString(freq);
    left->_cpu0.setString(cpu0);
    left->_cpu1.setString(cpu1);
    left->_cpu2.setString(cpu2);
    left->_cpu3.setString(cpu3);
    left->_cpu4.setString(cpu4);

    window->_window.draw(left->_CPU);
    window->_window.draw(left->_nbcore);
    window->_window.draw(left->_nbproc);
    window->_window.draw(left->_modname);
    window->_window.draw(left->_freq);

    left->_percentCpu0.setSize(sf::Vector2f(250 - ((100 - percent0) * 2.5), 5));
    left->_percentCpu1.setSize(sf::Vector2f(250 - ((100 - percent1) * 2.5), 5));
    left->_percentCpu2.setSize(sf::Vector2f(250 - ((100 - percent2) * 2.5), 5));
    left->_percentCpu3.setSize(sf::Vector2f(250 - ((100 - percent3) * 2.5), 5));
    left->_percentCpu4.setSize(sf::Vector2f(250 - ((100 - percent4) * 2.5), 5));
    left->_percentFrequancy.setSize(sf::Vector2f(250 - ((100 - percent) * 2.5), 5));

    if (left->nb_of_core > 0) {
        window->_window.draw(left->_cpu0);
        window->_window.draw(left->_percentCpu0);
    }
    if (left->nb_of_core > 1) {
        window->_window.draw(left->_cpu1);
        window->_window.draw(left->_percentCpu1);
    }
    if (left->nb_of_core > 2) {
        window->_window.draw(left->_cpu2);
        window->_window.draw(left->_percentCpu2);
    }
    if (left->nb_of_core > 3) {
        window->_window.draw(left->_cpu3);
        window->_window.draw(left->_percentCpu3);
    }
    if (left->nb_of_core > 4) {
        window->_window.draw(left->_cpu4);
        window->_window.draw(left->_percentCpu4);
    }
    window->_window.draw(left->_percentFrequancy);
}
