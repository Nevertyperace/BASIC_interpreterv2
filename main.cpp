
//-----------------------------------------
// Do not modify this file
//-----------------------------------------

#include "Program.h"
#include <fstream>

int main ( int argc, char** argv )
{
    if(argc==1)
    {
        std::cerr<<"You must pass an input file as a commandline argument. Correct usage is:\n"
                 << argv[0] <<" infilename"<<std::endl;
        exit(1);
    }

    //read input file into program
    std::ifstream in(argv[1]);
    if(!in.good())
    {
        std::cerr<<"Failed to open file at "<<argv[1]<<std::endl;
        exit(1);
    }
    Program prog;
    in >> prog;
    prog.run();
}

