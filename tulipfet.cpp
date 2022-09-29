#include <iostream>
#include <string>
using std::string;
using std::cout;

void print(string text, int spaces, string art) {
    cout << text;
    for (int i = 0; i != spaces; i++) {
        cout << " ";
    }
    cout << art << "\n";
}

int main () {
    string colours[5] = {"", "\033[0;31m", "\033[0;33m", "\033[0;34m", "\033[0;35m"}; // white, red, yellow, magenta, blue
    
    srand ( time(NULL) );

    int random = rand() % 5;
    int numSpaces;

    // operating system detection
    #ifdef __linux__
        string os = "linux";
        string username = getenv("USER");
    #elif __APPLE__
        string os = "mac";
        string username = getenv("USER");
    #elif _WIN32
        string os = "windows"
        string username = getenv("USERNAME");
    #elif BSD
        string os = "bsd";
        string username = getenv("USER");
    #else
        string os = "???";
        string username = "???";
    #endif

    int oslen = os.size();
    int usrlen = username.size();

    if (usrlen > oslen) {
        numSpaces = usrlen + 4;
    } else {
        numSpaces = oslen + 4;
    }

    cout << "\n";

    // flower
    //cout << colours[random];
    print(os, numSpaces - oslen, colours[random]+" (\")\033[0m");

    // stem
    print("", numSpaces, " \033[0;32m\\)/\033[0m");

    // username / pot
    print(username, numSpaces - usrlen, "\033[0;36m-----");
    // pot
    print("", numSpaces, "\\___/\033[0m");
}
