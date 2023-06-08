#include "Program.h"
#include "Input.h"


void Input::run()
{
    double a;
    std::cin >> a;

    Program::vars[varname] = a;

    Program::cur_cmd++;
}

Input::~Input()
{
    delete [] this;
}

void operator>>(std::string str, Input* obj)
{
    obj->varname = str.substr(str.find(" ", str.find(" ")+1)+1, string::npos);
}