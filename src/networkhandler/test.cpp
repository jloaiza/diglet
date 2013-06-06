
#include "test.h"

void Test::inMessage(std::string pMessage, int pSocket)
{
    std::cout << pMessage << std::endl;
    if (!strncmp(pMessage.c_str(), "disconnect", 10))
    {
        NetworkHandler::disconnectClient();
    }
    else if(!strncmp(pMessage.c_str(), "closeserver", 11))
    {
        NetworkHandler::closeServer();
    }
    else if(!strncmp(pMessage.c_str(), "isConnect", 9))
    {
        std::cout << "WIII SI ESTA CONECTADO" << std::endl;
    }   
}

