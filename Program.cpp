#include "Program.h"

map<int, Command*> Program::cmds;
map<int, Command*>::iterator Program::cur_cmd;
map<string, double> Program::vars;

void Program::run()
{
    cur_cmd = cmds.begin();

    while (cur_cmd != cmds.end())
    {
        //std::cout << "\ncur_cmd->first: " << cur_cmd->first << "\n";
        this->cmds[cur_cmd->first]->run();
    }
}

void operator>>(std::ifstream &input, Program program)
{    
    std::string new_line, line_num, comm;
    
    while(std::getline(input, new_line, '\n'))
    {
        if (new_line.back() == 13) new_line.pop_back();

        line_num = new_line.substr(0, new_line.find_first_of(" "));
        int int_line_num = std::stoi(line_num);

        comm = new_line.substr(new_line.find(" ")+1, new_line.find(" ", new_line.find(" ")+1)-new_line.find(" ")-1);

        if (comm == "PRINT")
        { 
            Print *cmd_ptr = new Print;
            program.cmds.insert({int_line_num, cmd_ptr});
            new_line >> cmd_ptr;
        }
        else if (comm == "GOTO")
        {
            Goto *cmd_ptr = new Goto;
            program.cmds.insert({int_line_num, cmd_ptr});
            new_line >> cmd_ptr;
        }
        else if (comm == "INPUT")
        {
            Input *cmd_ptr = new Input;
            program.cmds.insert({int_line_num, cmd_ptr});
            new_line >> cmd_ptr;
        }
        else if (comm == "LET")
        {
            Let *cmd_ptr = new Let;
            program.cmds.insert({int_line_num, cmd_ptr});
            new_line >> cmd_ptr;
        }
        else if (comm == "IF")
        {
            If *cmd_ptr = new If;
            program.cmds.insert({int_line_num, cmd_ptr});
            
            Program prog2;
            input >> prog2;

            new_line >> cmd_ptr;
        }
        else if (comm == "ENDIF")
        {
            return;
        }
    }
}