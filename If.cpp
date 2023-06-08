#include "If.h"

If::~If()
{
    delete [] this;
}

void If::run()
{
    double var1_revised, var2_revised;
    bool var1_is_a_var = false;
    bool var2_is_a_var = false;

    for (char c : var1) if (c!=46 && c!=45 && c < 48 || c > 57) var1_is_a_var = true;
    //var1 is a variable
    if(var1_is_a_var==true) var1_revised = Program::vars[var1]; 
    //var1 is a constant
    else var1_revised = std::stod(var1);

    for (char c : var2) if (c!=46 && c!=45 && c < 48 || c > 57) var2_is_a_var = true;
    //var2 is a variable
    if(var2_is_a_var==true) var2_revised = Program::vars[var2];    
    //var2 is a constant
    else var2_revised = std::stod(var2);

    if (op == "==") 
    {
        if (var1_revised == var2_revised) Program::cur_cmd++; //GOTO NEXT LINE;  
        else Program::cur_cmd = std::next(end_cmd); //GOTO ENDIF
    }
    else if (op == "!=") 
    {
        if (var1_revised != var2_revised) Program::cur_cmd++; //GOTO NEXT LINE;   
        else Program::cur_cmd = std::next(end_cmd); //GOTO ENDIF
    }
    else if (op == ">") 
    {
        if (var1_revised > var2_revised) Program::cur_cmd++; //GOTO NEXT LINE;   
        else Program::cur_cmd = std::next(end_cmd); //GOTO ENDIF
    }
    else if (op == "<") 
    {
        if (var1_revised < var2_revised) Program::cur_cmd++; //GOTO NEXT LINE;   
        else Program::cur_cmd = std::next(end_cmd); //GOTO ENDIF
    }
}

void operator>>(std::string str, If* obj)
{
    obj->end_cmd = std::prev(Program::cmds.end());

    str.erase(str.find_first_of(" "), 1); //10IF A == B THEN
    obj->var1 = str.substr(str.find(" ")+1, str.find(" ", str.find(" ")+1)-str.find(" ")-1);
    str.erase(str.find_first_of(" "), 1); //10IFA == B THEN
    obj->op = str.substr(str.find(" ")+1, str.find(" ", str.find(" ")+1)-str.find(" ")-1);
    str.erase(str.find_first_of(" "), 1); //10IFA== B THEN
    if (str.find_first_of(" ") != string::npos)
        obj->var2 = str.substr(str.find(" ")+1, str.find(" ", str.find(" ")+1)-str.find(" ")-1);
    else obj->var2 = str.substr(str.find(" ")+1, string::npos);
}