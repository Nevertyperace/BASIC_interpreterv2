#include "Program.h"
#include "Goto.h"


void Goto::run()
{
    Program::cur_cmd = Program::cmds.find(target_line);
}

Goto::~Goto()
{
    delete [] this;
}

void operator>>(std::string str, Goto* obj)
{
    //get the argument for the goto command (target_line)
    obj->target_line = std::stoi(str.substr(str.find(" ", str.find(" ")+1)+1, string::npos));
}