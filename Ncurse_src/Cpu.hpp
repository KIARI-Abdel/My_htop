/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** CPU
*/

#ifndef CPU_HPP
#define CPU_HPP

#include "MonitorModule.hpp"

using namespace std;

class Cpu : public AMonitorModule
{
  public:
    Cpu();
    ~Cpu();
    int getProcs() const;
    vector<std::size_t> get_cpu_times(int);
    bool get_cpu_times(std::size_t &idle_time, std::size_t &total_time, int);
    float getIdle();
    string getNbCore() const;
    string init_name() const;
    string getCpuName() const;
    vector<int> getActivity();
    vector<std::string> getCache() const;

  private:
    int _procs;
    float _idle;
    vector<int> _activity;
    vector<std::string> _caches;
    string _nb_core;
    string _name;
};

#endif //CPU_HPP
