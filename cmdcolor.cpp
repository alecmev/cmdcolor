#include <cstring>
#include <iostream>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

const int ntow[] = { 0, 4, 2, 6, 1, 5, 3, 7 };

int parse(bool *fore) {
    char c, d;
    if (!cin.get(c).good()) {
        throw -1;
    }
    c -= '0';
    if (c == 0) {
        throw -2;
    }
    if (!cin.get(d).good()) {
        throw -1;
    }
    d -= '0';
    if (d < 0 || d > 7) {
        throw -1;
    }
    if (c == 1) {
        if (d != 0 || !cin.get(d).good()) {
            throw -1;
        }
    }

    int res = ntow[d];
    switch (c) {
        case 3: {
            *fore = true;
            return res;
        }
        case 4: {
            *fore = false;
            return res << 4;
        }
        case 9: {
            *fore = true;
            return res + 8;
        }
        case 1: {
            *fore = false;
            return (res + 8) << 4;
        }
        default: {
            throw -1;
        }
    }
}

int main() {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO definfo;
    GetConsoleScreenBufferInfo(con, &definfo);
    try {
        char c;
        while (cin.get(c).good()) {
            if (c == '\\') {
                if (!cin.get(c).good()) {
                    cout << '\\';
                    throw -1;
                }
                if (c != '0') {
                    cout << '\\' << c;
                    continue;
                }
                if (!cin.get(c).good()) {
                    cout << "\\0";
                    throw -1;
                }
                if (c != '3') {
                    cout << "\\0" << c;
                    continue;
                }
                if (!cin.get(c).good()) {
                    cout << "\\03";
                    throw -1;
                }
                if (c != '3') {
                    cout << "\\03" << c;
                    continue;
                }

                c = 27;
            }
            if (c != 27) {
                cout << c;
                continue;
            }
            if (!cin.get(c).good()) {
                cout << (char)27;
                throw -1;
            }
            if (c != '[') {
                cout << (char)27 << c;
                continue;
            }

            int res = 0;
            bool fore;
            
            do {
                try {
                    res = parse(&fore) + (res & (fore ? 0xF0 : 0x0F));
                }
                catch (int e) {
                    if (e == -2) {
                        res = definfo.wAttributes;
                    }
                    else {
                        throw;
                    }
                }
                
                if (!cin.get(c).good()) {
                    throw -1;
                }
            } while (c == ';');

            if (c != 'm') {
                continue;
            }

            SetConsoleTextAttribute(con, res);
        }
    }
    catch (int e) {
    }

    SetConsoleTextAttribute(con, definfo.wAttributes);
}
