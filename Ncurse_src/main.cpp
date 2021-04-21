/*
** EPITECH PROJECT, 2018
** MAIN
** File description:
** file
*/

#include"Ncurse.hpp"
#include"Sfml.hpp"

using namespace std;

void display_usage(void)
{
    cout << "USAGE :" << endl;
    cout << "\t\t./MyGKrellm\t[MODE]" << endl;
    cout << endl;
    cout << "- Mode :\t\t\t--> \"text\" to start in ncurse mode" << endl;
    cout << "\t\t\t\t--> \"graphical\" to start in sfml mode" << endl;
    cout << "\t\t\t\t--> \"-h\" or \"--help\" to show usage mode" << endl;
}

int main(int ac, char *av[])
{
    IMonitorDisplay *mode;
    if (ac == 2 && (strcmp(av[1], "text") == 0))
        mode = new Ncurse;
    else if (ac == 2 && (strcmp(av[1], "graphical") == 0))
        mode = new Sfml;
    else if ((ac == 2) && ((strcmp(av[1], "-h") == 0) || (strcmp(av[1], "--help") ==0))) {
            display_usage();
            return 84;
    } else {
        cerr << "Invalid mode, try with -h or --help" << endl;
        return 84;
    }
    mode->start();
    return 0;
}
