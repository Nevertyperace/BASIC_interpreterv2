#ifndef BASIC_PRINT_H
#define BASIC_PRINT_H

#include "Command.h"
#include <string>

class Print:public Command{
private:
    std::string message;

public:
    Print(){};
    ~Print();
    void run();

    friend void operator>>(std::string str, Print* obj);
};

#endif //BASIC_PRINT_H
