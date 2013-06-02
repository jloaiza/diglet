#include "session.h"

int Session::_counter = 0;

Session::Session(std::string pUser){
	_user = pUser;
	_sessionID = _counter++;
	_seek = -1;
	_currentPath = "/";
	_consoleMode = false;
	_disk = 0;
	_currentNode = 0;
	_register = 0;
}
