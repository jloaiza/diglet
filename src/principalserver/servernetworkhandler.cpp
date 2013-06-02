#include "servernetworkhandler.h"
#include "serveroperations.h"
#include "../tokenizer.h"
#include <exception>

#include <iostream>

int ServerNetworkHandler::_sessionID = -1;

void ServerNetworkHandler::inMessage(std::string pMessage, int pSocket){
	pMessage = Tokenizer::cleanEntry(pMessage);
	std::string command = Tokenizer::getCommandSpace(pMessage, 1);
	if (command != "connect" && command != "adduser" && _session == 0){
		outMessage("?Error: No se ha inciado sesión\n", pSocket);
	} else {

		std::string param = Tokenizer::getParameters(pMessage);
		std::cout<<param<<std::endl;
		if (command == "get"){
			get(param, pSocket);

		} else if (command == "cd"){
			cd(param, pSocket);
		
		} else if (command == "rm"){
			rm(param, pSocket);

		} else if (command == "touch"){
			touch(param, pSocket);

		} else if (command == "connect"){
			connect(param, pSocket);

		} else if (command == "adduser"){
			adduser(param, pSocket);

		} else if (command == "openfile"){
			openfile(param, pSocket);

		} else if (command == "appendReg"){
			appendReg(param, pSocket);

		} else if (command == "delReg"){

			if (param == ""){
				delActualReg(pSocket);
			} else {
				delReg(param, pSocket);
			}
		
		} else if (command == "write"){
			write(param, pSocket);
		
		} else if (command == "seek"){
			seek(param, pSocket);
		
		} else if (command == "addReg"){
			addReg(param, pSocket);
		
		} else if (command == "read"){

			if (param == ""){
				readActual(pSocket);
			} else {
				readRegister(param, pSocket);
			}

		} else if (command == "close"){
			close(pSocket);
		
		} else if (command == "disconnect"){
			//zczxc
			
		} else if (command == "consoleMode"){
			consoleMode(param, pSocket);
		} else {
			outMessage("?Error: No se ha encontrado la instrucción " + command + '\n', pSocket);
		}
		consoleUI(pSocket);
	}
}

void ServerNetworkHandler::consoleMode(std::string pParameters, int pSocket){
	std::string param = Tokenizer::getCommandSpace(pParameters, 1);
	std::cout<<param<<std::endl;
	if (param == "false"){
		_session->setConsoleMode(false);
	} else if (param == "true"){
		_session->setConsoleMode(true);
	} else {
		outMessage("?Error: El comando 'consoleMode' espera un boolean true/false\n", pSocket);
	}
}

void ServerNetworkHandler::consoleUI(int pSocket){
	if (_session != 0 && _session->isOnConsoleMode()){
		std::string message = /*getIp()*/ std::string("127.0.0.1") + std::string("@") + _session->getUser() + std::string(":~") + _session->getCurrentPath() + std::string(">> ");
		outMessage(message, pSocket);
	}
}

void ServerNetworkHandler::outMessageValidate(std::string pMessage, int pSocket){
	if (pMessage != ""){
		outMessage(pMessage, pSocket);
	}
}

void ServerNetworkHandler::get(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'get' espera un parametro\n", pSocket);
	} else {
		std::string path = Tokenizer::getCommandSpace(pParameters, 1);
		outMessageValidate(ServerOperations::get(_session, path), pSocket);
	}
}

void ServerNetworkHandler::cd(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'cd' espera un parametro\n", pSocket);
	} else {
		std::string path = Tokenizer::getCommandSpace(pParameters, 1);
		outMessageValidate(ServerOperations::cd(_session, path), pSocket);
	}
}

void ServerNetworkHandler::rm(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'rm' espera un parametro\n", pSocket);
	} else {
		std::string path = Tokenizer::getCommandSpace(pParameters, 1);
		outMessageValidate(ServerOperations::rm(_session, path), pSocket);
	}
}

void ServerNetworkHandler::touch(std::string pParameters, int pSocket){
	std::string path = Tokenizer::getCommandSpace(pParameters, 1);
	std::string format = Tokenizer::getCommandSpace(pParameters, 3);

	if (format == ""){
		outMessage("?Error: El comando 'touch' espera tres parametros\n", pSocket);
	} else {
		outMessageValidate(ServerOperations::touch(_session, path, format), pSocket);
	}

}

void ServerNetworkHandler::connect(std::string pParameters, int pSocket){
	std::string user = Tokenizer::getCommandSpace(pParameters, 1);
	std::string secKey = Tokenizer::getCommandSpace(pParameters, 2);
	std::string disk = Tokenizer::getCommandSpace(pParameters, 3);

	if (disk == ""){
		outMessage("*Error de implementación: El comando interno 'connect' espera tres parametros\n", pSocket);
	} else {
		_session = ServerOperations::connect(user, secKey, disk);
		if (_session == 0){
			outMessage("Error de autenticación, nombre de usuario o contraseña incorrectos\n", pSocket);
		} 
	}

}

void ServerNetworkHandler::adduser(std::string pParameters, int pSocket){
	std::string user = Tokenizer::getCommandSpace(pParameters, 1);
	std::string secKey = Tokenizer::getCommandSpace(pParameters, 2);
	std::string disk = Tokenizer::getCommandSpace(pParameters, 3);

	if (disk == ""){
		outMessage("*Error de implementación: El comando interno 'adduser' espera tres parametros\n", pSocket);
	} else {
		_session = ServerOperations::adduser(user, secKey, disk);
		if (_session == 0){
			outMessage("Error de registro, el nombre de usuario ya existe\n", pSocket);
		}
	}
}

void ServerNetworkHandler::openfile(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'openfile' espera un parametro\n", pSocket);
	} else {
		std::string path = Tokenizer::getCommandSpace(pParameters, 1);
		outMessageValidate(ServerOperations::openfile(_session, path), pSocket);
	}
}

void ServerNetworkHandler::appendReg(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'appendReg' espera un parametro\n", pSocket);
	} else {
		std::string data = Tokenizer::getCommandSpace(pParameters, 1);
		outMessageValidate(ServerOperations::appendReg(_session, data), pSocket);
	}
}

void ServerNetworkHandler::delActualReg(int pSocket){
	int seek = _session->getSeek();
	outMessageValidate(ServerOperations::delReg(_session, seek), pSocket);
}

void ServerNetworkHandler::delReg(std::string pParameters, int pSocket){
	try {
		int regNum = stoi( Tokenizer::getCommandSpace(pParameters, 1) );
		outMessageValidate(ServerOperations::delReg(_session, regNum), pSocket);
	} catch (std::exception e){
		outMessage("?Error: Se esperaba un número\n", pSocket);
	}
}

void ServerNetworkHandler::write(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'write' espera al menos un parametro\n", pSocket);
	} else {
		std::string data = Tokenizer::getCommandSpace(pParameters, 1);

		if (Tokenizer::getCommandSpace(pParameters, 2) == ""){

			int seek = _session->getSeek();
			outMessageValidate(ServerOperations::write(_session, data, seek), pSocket);

		} else {

			try {

				int regNum = stoi( Tokenizer::getCommandSpace(pParameters, 2) );
				outMessageValidate(ServerOperations::write(_session, data, regNum), pSocket);

			} catch (std::exception e){
				outMessage("?Error: El segundo parametro de write debe ser un número\n", pSocket);
			}
		}
	}
}

void ServerNetworkHandler::seek(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'seek' espera un parametro\n", pSocket);
	} else {
		try {
			int seek = stoi( Tokenizer::getCommandSpace(pParameters, 1) );
			_session->setSeek(seek);
		} catch (std::exception& e) {
			outMessage("?Error: Se esperaba un número\n", pSocket);
		}
	}
}

void ServerNetworkHandler::addReg(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'addReg' espera un parametro\n", pSocket);
	} else {
		std::string data = Tokenizer::getCommandSpace(pParameters, 1);
		int seek = _session->getSeek();
		outMessageValidate(ServerOperations::write(_session, data, seek), pSocket);
	}
}

void ServerNetworkHandler::readActual(int pSocket){
	int seek = _session->getSeek();
	outMessageValidate(ServerOperations::readReg(_session, seek), pSocket);
}

void ServerNetworkHandler::readRegister(std::string pParameters, int pSocket){
	if (pParameters == ""){
		outMessage("?Error: El comando 'readRegister' espera un parametro\n", pSocket);
	} else {
		try {
				int regNum = stoi( Tokenizer::getCommandSpace(pParameters, 1) );
				outMessageValidate(ServerOperations::readReg(_session, regNum), pSocket);
			} catch (std::exception e){
				outMessage("?Error: Se esperaba un número\n", pSocket);
			}
	}
}

void ServerNetworkHandler::close(int pSocket){
	outMessage(ServerOperations::close(_session), pSocket);
}

int main(){
	ServerNetworkHandler* server = new ServerNetworkHandler();
	server->Run();
	return 0;
}