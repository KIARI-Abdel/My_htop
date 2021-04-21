/*
** EPITECH PROJECT, 2020
** cpp_rush3
** File description:
** CPU
*/

#include "Cpu.hpp"

using namespace std;

Cpu::Cpu()
{
    struct sysinfo info;
    sysinfo(&info);
    _activity = getActivity();
    _procs = info.procs;
    _idle = 100 - _activity[0];
    _name = init_name();
    system("cat /proc/stat | grep cpu | wc -l > data.txt");
    ifstream f("data.txt", std::ifstream::in);
    string tmp;
    getline(f, tmp);
    _nb_core = tmp;
}

Cpu::~Cpu()
{

}

int Cpu::getProcs() const
{
    return _procs;
}

string Cpu::init_name() const
{
    system("cat /proc/cpuinfo | grep \"model name\" > data.txt" );
    ifstream f_name("data.txt", std::ifstream::in);
    string new_name;
    f_name.ignore(18, ':');
    getline(f_name, new_name);
    return new_name;
}


bool Cpu::get_cpu_times(size_t &idle_time, size_t &total_time, int i)
{
    const vector<size_t> cpu_time = get_cpu_times(i);
    if (cpu_time.size() < 4)
        return false;
    idle_time = cpu_time[3];
    total_time = std::accumulate(cpu_time.begin(), cpu_time.end(), 0);
    return true;
}

std::vector<size_t> Cpu::get_cpu_times(int i)
{
    ifstream proc_stat("/proc/stat");
    string line;
    if (i == 0)
        std::getline(proc_stat, line);
    if (i != 0) {
        while (i != 0) {
            getline(proc_stat, line);
            i--;
        }
    }
    proc_stat.ignore(5, ' ');
    vector<size_t> times;
    for (size_t time; proc_stat >> time; times.push_back(time));
    return times;
}


float Cpu::getIdle()
{
    return _idle;
}

string Cpu::getCpuName() const
{
    return _name;
}

string Cpu::getNbCore() const
{
    return _nb_core;
}

std::vector<int> Cpu::getActivity()
{
    vector<int> activity;
    system("cat /proc/stat | grep cpu | wc -l > data.txt");
    ifstream file("data.txt", std::ifstream::in);
    string tmp;
    getline(file, tmp);
    int val = 0;
    int pos = 0;
    try {
            val = stoi(tmp);
    } catch (invalid_argument &e) {
    }
    for (int i = 0; i != val; i++) {
        size_t previous_idle_time=0, previous_total_time=0;
        size_t idle_time, total_time;
        get_cpu_times(idle_time, total_time, pos);
        const float idle_time_delta = idle_time - previous_idle_time;
        const float total_time_delta = total_time - previous_total_time;
        const float utilization = 100.0 * (1.0 - idle_time_delta / total_time_delta);
        activity.push_back(utilization);
        previous_idle_time = idle_time;
        previous_total_time = total_time;
        pos++;
    }
    return activity;
}

