/*
** EPITECH PROJECT, 2019
** cpp_rush3
** File description:
** Ncurse
*/

#include "Ncurse.hpp"

using namespace std;

Ncurse::Ncurse()
    : IMonitorDisplay()
{
}
void drawArt(WINDOW *_win, int y, int x, std::string file_name)
{
    string line;
    ifstream myfile(file_name);

    if (myfile.is_open()) {
        while (getline(myfile, line))
            mvwprintw(_win, y++, x - line.size(), line.c_str());
    }
}

void drawRect(int x, int y, int width, int height, char ch)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == (height - 1))
                mvaddch(y + i, x + j, ch);
            else if (j == 0 || j == (width - 1))
                mvaddch(y + i, x + j, ch);
        }
    }
}

void drawHeadInfo(windows *_win, User *_user)
{
    int max_x             =  getmaxx(stdscr);
    string _time     = _user->getTime();
    string _date     = _user->getDate();
    string _bootTime = to_string(_user->getUpTime());
    _bootTime             = "Time since last boot: " + _bootTime;
    
    mvwprintw(_win->_headWin, 2, 10, _user->getUserName().c_str());
    mvwprintw(_win->_headWin, 3, 10, _user->getHostName().c_str());
    mvwprintw(_win->_headWin, 4, 10, _user->getOs().c_str());
    mvwprintw(_win->_headWin, 5, 10, _user->getKernel().c_str());
    
    drawArt(_win->_headWin, 1, (max_x / 2) + 5, "head_art.txt");

    mvwprintw(_win->_headWin, 2, (max_x - _date.size() - 10), _date.c_str());
    mvwprintw(_win->_headWin, 3, (max_x - _time.size() - 10), _time.c_str());
    mvwprintw(_win->_headWin, 4, (max_x - _bootTime.size() - 10),  _bootTime.c_str());
    wrefresh(_win->_headWin);
}

void drawCpu(WINDOW *_win, Cpu *_cpu)
{
    int max_x   = getmaxx(_win);
    int _cores  = stoi(_cpu->getNbCore()) - 1;
    vector<int> _act    = _cpu->getActivity();
    mvwprintw(_win, 2, (max_x / 2), "CPU");
    mvwprintw(_win, 4, 5, "Nb of Cores =>  %d", _cores);
    mvwprintw(_win, 6, 5, "Nb of Procceses => %d", _cpu->getProcs());
    mvwprintw(_win, 8, 5, "Name => %s", _cpu->getCpuName().c_str());
    
    mvwprintw(_win, 10, 5, "Frequency => %d", _act[0]);

    int k = 1;
    for (int i = 0; i < _cores; i++) {
        string tmp = "Cpu" + std::to_string(i) + " => ";
        mvwprintw(_win, 12 + i + 1 + k, 5, tmp.c_str());
        mvwprintw(_win, 12 + i + 1 + k, 5 + tmp.size(), to_string(_act[i]).c_str());
        k++;
    }
    wrefresh(_win);
}


void drawMemory(WINDOW *_win, Memory *_mem)
{
    int max_x               = getmaxx(_win);
    string _ramTotal   = to_string(_mem->getTotalRam());
    string _ramShared  = to_string(_mem->getSharedRam());
    string _swapTotal  = to_string(_mem->getTotalSwap());
    string _swapShared = to_string(_mem->getFreeSwap());
    
    mvwprintw(_win, 2, max_x / 2, "MEMORY");
    
    mvwprintw(_win, 4, 5, "RAM");
    mvwprintw(_win, 6, 7, "Total => %s", _ramTotal.c_str());
    mvwprintw(_win, 8, 7, "Shared => %s", _ramShared.c_str());

    mvwprintw(_win, 10, 5, "SWAP");
    mvwprintw(_win, 12, 7, "Total => %s", _swapTotal.c_str());
    mvwprintw(_win, 14, 7, "Shared => %s", _swapShared.c_str());

    wrefresh(_win);
}

void drawNetwork(WINDOW *_win, Network *_net)
{
    int max_x = getmaxx(_win);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    mvwprintw(_win, 2, (max_x/ 2) , "NETWORK");
    mvwprintw(_win, 4, 5, "IP Adress => %s", _net->getIp().c_str());
    mvwprintw(_win, 6, 5, "Device => %s", _net->getDevice().c_str());
    mvwprintw(_win, 8, 5, "Incoming Bandwidth => %s", _net->getIncomingByte().c_str());
    mvwprintw(_win,10, 5, "Transmitting Bandwidth => %s", _net->getOutgoingByte().c_str());
    wrefresh(_win);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	
    WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    wattron(local_win, COLOR_PAIR(1));
    wborder(local_win, '*', '*', '~', '~', '*', '*', '+', '+');
    wattroff(local_win, COLOR_PAIR(1));
    wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win)
{
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);
}

void drawWindow(windows *_wins)
{
    int max_width      =  getmaxx(stdscr);
    _wins->_headWin    = create_newwin(10, max_width, 0, 0);
    _wins->_cpuWin     = create_newwin(30, (max_width / 3), 10, 0);
    _wins->_memWin     = create_newwin(30, (max_width / 3), 10, (max_width / 3));
    _wins->_networkWin = create_newwin(30, (max_width / 3), 10, (max_width / 3) * 2);
    _wins->_cpuActive  = true;
    _wins->_memActive  = true;
    _wins->_netActive  = true;
}


bool evenHandler(windows *_wins, char ch)
{
    if (ch == 27)
        return true;
    if (ch == KEY_F(1))
        _wins->_cpuActive = !_wins->_cpuActive;
    if (ch == KEY_F(2))
        _wins->_memActive = !_wins->_memActive;
    if (ch == KEY_F(3))
        _wins->_netActive = !_wins->_netActive;
    return false;
}

void initWin()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
}

void Ncurse::start()
{
    initWin();
    char ch;
    User *_user   = new User;
    Cpu *_cpu     = new Cpu;
    Network *_net = new Network;
    Memory *_mem  = new Memory;
    refresh();
    windows _wins;
    drawWindow(&_wins);
    while((ch = getch() != 27)) {
        if (evenHandler(&_wins, ch))
            break;
        drawHeadInfo(&_wins, _user);
        if (_wins._cpuActive)
            drawCpu(_wins._cpuWin, _cpu);
        if (_wins._memActive)
            drawMemory(_wins._memWin, _mem);
        if (_wins._netActive)
            drawNetwork(_wins._networkWin, _net);
        refresh();
    }
    endwin();
}
