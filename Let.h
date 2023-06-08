#ifndef BASIC_LET_H
#define BASIC_LET_H

#include "Command.h"
#include <sstream>


class Let:public Command{
private:
    std::string outname;
    std::string arg1;
    std::string arg2;
    std::string op;
    
public:
    Let(){};
    ~Let();
    void run();

    friend void operator>>(std::string str, Let* obj);
};


#endif //BASIC_LET_H
