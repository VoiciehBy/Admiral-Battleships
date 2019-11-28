#include "utility.h"

void pause_n_clear()
{
#ifdef _WIN32
    system("PAUSE");
    system("CLS");
#elif __unix__
    system("echo Press any key to continue");
    system("read -p ... .");
    system("clear");
#elif __APPLE__
    cout << "APPLE..." << endl;
    system("echo Press any key to continue");
    system("read -p ... .");
    system("clear");
#else
    cout << "OS not supported!" << endl;
#endif
}
