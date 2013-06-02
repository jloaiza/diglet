#ifndef SESSION
#define SESSION

#include <string>
#include "registerspace.h"
#include "diskgroup.h"
#include "../structures/ntree/ntreenode.h"

class Session {
private:

	static int _counter;
	int _sessionID;
	int _seek;
	bool _consoleMode;
	DiskGroup* _disk;
	nTreeNode* _currentNode;
	RegisterSpace* _register;
	std::string _user;
	std::string _currentPath;

public:
	Session(std::string pUser);
	
	int getSeek() const {
		return _seek;
	}

	void setSeek(int pSeek){
		_seek = pSeek;
	}

	bool isOnConsoleMode() const{
		return _consoleMode;
	}

	void setConsoleMode(bool pValue) {
		_consoleMode = pValue;
	}

	std::string getUser() const{
		return _user;
	}

	std::string getCurrentPath() const {
		return _currentPath;
	}

};


#endif /* SESSION */