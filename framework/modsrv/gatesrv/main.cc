#include "stdafx.h"


int main(int argc, char** argv)
{
    Srvapp::main(argc, argv);
    Neox::lua_openlibs(Srvapp::L);
    Srvapp::lua_dofile("srvapp.lua");
    return 0;
}
