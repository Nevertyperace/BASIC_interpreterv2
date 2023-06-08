#ifndef BASIC_IF_H
#define BASIC_IF_H

#include "Program.h"
#include "Command.h"
#include <map>


class If:public Command{
private:
    std::string var1;
    std::string var2;
    std::string op;
    std::map<int, Command*>::iterator end_cmd;
    
public:
    If(){};
    ~If();
    void run();

    friend void operator>>(std::string str, If* obj);
};


#endif //BASIC_IF_H
