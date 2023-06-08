#include "Program.h"
#include "Let.h"


void Let::run()
{
    double arg1_revised, arg2_revised;
    bool arg1_is_a_var = false;
    bool arg2_is_a_var = false;

    for (char c : arg1)
    {
        if (c!=46 && c!=45 && c < 48 || c > 57) arg1_is_a_var = true;
    } 
    
    //arg1 is a variable
    if(arg1_is_a_var==true) arg1_revised = Program::vars[arg1]; 
    //arg1 is a constant
    else arg1_revised = std::stod(arg1);

    if (!arg2.empty())
    {
        for (char c : arg2) if (c!=46 && c!=45 && c < 48 || c > 57) arg2_is_a_var = true;

        //arg2 is a variable
        if(arg2_is_a_var==true) arg2_revised = Program::vars[arg2];    
        //arg2 is a constant
        else arg2_revised = std::stod(arg2);
    }

    if (op.empty()) Program::vars[outname] = arg1_revised;
    else if (op == "+") Program::vars[outname] = arg1_revised + arg2_revised;
    else if (op == "-") Program::vars[outname] = arg1_revised - arg2_revised;
    else if (op == "*") Program::vars[outname] = arg1_revised * arg2_revised;
    else if (op == "/") Program::vars[outname] = arg1_revised / arg2_revised;

    Program::cur_cmd++;
}

Let::~Let()
{
    delete [] this;
}

void operator>>(std::string str, Let* obj)
{
            std::string result, args1, myop, args2, temp;

            temp = str;
            temp.erase(temp.find_first_of(" "), 1);
            result = temp.substr(temp.find(" ")+1, temp.find(" ", temp.find(" ")+1)-temp.find(" ")-1);
            temp.erase(temp.find_first_of(" "), 1);
            temp.erase(temp.find_first_of(" "), 1);
            args1 = temp.substr(temp.find(" ")+1, temp.find(" ", temp.find(" ")+1)-temp.find(" ")-1);
            temp.erase(temp.find_first_of(" "), 1);

            if (temp.find_first_of(" ") != string::npos)
            {
                //This is a computation
                myop = temp.substr(temp.find(" ")+1, temp.find(" ", temp.find(" ")+1)-temp.find(" ")-1);
                temp.erase(temp.find_first_of(" "), 1);
                args2 = temp.substr(temp.find(" ")+1, string::npos);

                obj->outname = result;
                obj->arg1 = args1;
                obj->op = myop;
                obj->arg2 = args2;
            }
            else
            {
                //This a variable declaration
                obj->outname = result;
                obj->arg1 = args1;
            }
}