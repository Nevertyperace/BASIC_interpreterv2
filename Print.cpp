#include "Print.h"
#include "Program.h"
#include <string.h>


void Print::run()
{
    //std::cout << (int)message[0] << "\n";
    //if we are printing a string
    if (message.find_first_of("\"") != string::npos)
    {
        std::string print_message;
        print_message = message.substr(message.find("\"")+1, message.rfind("\"")-message.find("\"")-1);
        
        size_t pos = 0;
        const char CR = 10;
        pos = print_message.find("\\n", pos);
        while (pos != string::npos)
        {
            print_message.replace(pos, 2, 1, CR);
            pos = print_message.find("\\n", pos);
        } 

        std::cout << print_message; //<< std::endl;
    }
    //we are printing a variable
    else
    {
        std::cout << Program::vars[message]; //<< std::endl;
    }

    
    Program::cur_cmd++;
}

Print::~Print()
{
    delete [] this;
}

void operator>>(std::string str, Print* obj)
{
    obj->message = str.substr(str.find(" ", str.find(" ")+1)+1, string::npos);
}