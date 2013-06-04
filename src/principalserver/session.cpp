#include "session.h"

int Session::_sessionCounter = 0;

Session::Session(std::string pUser){
	_user = pUser;
	_sessionID = _sessionCounter++;
	_seek = -1;
	_currentPath = "/";
	_disk = 0;
	_currentNode = 0;
	_register = 0;
}
