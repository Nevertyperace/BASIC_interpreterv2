#ifndef BASIC_GOTO_H
#define BASIC_GOTO_H

#include "Command.h"


class Goto:public Command{
private:
    int target_line;
    
public:
    Goto(){};
    ~Goto();
    void run();

    friend void operator>>(std::string str, Goto* obj);
};

#endif //BASIC_GOTO_H
