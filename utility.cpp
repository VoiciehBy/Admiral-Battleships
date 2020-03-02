#include "utility.h"

void pause_n_clear()
{
    cout << "Press any key to continue" << endl;
    char ch;
    cin.get(ch);
#ifdef _WIN32
    system("CLS");
#elif __unix__
    system("clear");
#elif __APPLE__
    cout << "APPLE..." << endl;
    system("clear");
#else
    cout << "OS not supported!" << endl;
#endif
}
