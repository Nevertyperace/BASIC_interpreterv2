#ifndef BASIC_INPUT_H
#define BASIC_INPUT_H

#include "Command.h"


class Input:public Command{
private:
    std::string varname;
    
public:
    Input(){};
    ~Input();
    void run();

    friend void operator>>(std::string str, Input* obj);
};


#endif //BASIC_INPUT_H
