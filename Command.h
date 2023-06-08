#ifndef COMMAND_H_
#define COMMAND_H_

//-----------------------------------------
// Do not modify this file
//-----------------------------------------

#include <iostream>
class Program; //predeclare

class Command {
public:
    Command(){};
    virtual ~Command(){};
    virtual void run()=0;
};

#endif /* COMMAND_H_ */
