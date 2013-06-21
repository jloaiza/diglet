#ifndef SERVERCONSOLE
#define SERVERCONSOLE

#include <thread>


class ServerConsole{
public:
	ServerConsole(GeneralManager* pManager){
		_manager = pManager;
		_onRun = true;
	}

	void start();
	void stop();

	std::thread* getThread() const {
		return _thread;
	}

private:
	void createDiskGroup();
	
	static void callRun(ServerConsole* pConsole);
	void run();
	void title();
	bool _onRun;
	GeneralManager* _manager;
	std::thread* _thread;



};



#endif /* SERVERCONSOLE */