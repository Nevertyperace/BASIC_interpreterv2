#ifndef BASIC_PROGRAM_H
#define BASIC_PROGRAM_H

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "Command.h"
#include "Print.h"
#include "Let.h"
#include "Goto.h"
#include "If.h"
#include "Input.h"
using namespace std;


class Program {
public:
    static map<int, Command*> cmds;
    static map<int, Command*>::iterator cur_cmd;
    static map<string, double> vars;

    Program(){};
    ~Program(){};
    void run();

    friend void operator>>(std::ifstream &input, Program prog);
};


#endif //BASIC_PROGRAM_H
