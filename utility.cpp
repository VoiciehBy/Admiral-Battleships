#include "utility.h"

void pause_n_clear()
{
  println("Press any key to continue");
    char ch;
    cin.get(ch);
#ifdef _WIN32
    system("CLS");
#elif __unix__
    system("clear");
#elif __APPLE__
  println("APPLE...");
    system("clear");
#else
  println("OS not supported!");
#endif
}

void println(std::string str) {
    std:: cout << str << std::endl;
}

void println(std::string str,int value) {
    std:: cout << str << value << std::endl;
}

void breakLine() {
    printf("\n");
}
