#include "tokenizer.h"

const char Tokenizer::_restringedChars[] = {'\n', '\f', '\0', '\b', '\r', '\t', '\v'};

int Tokenizer::charIndex(std::string pString, char pChar, int pNumber){
	int index = -1;
	for (;pNumber > 0;pNumber--){

		if (index > (int)pString.length()) {
			return -1;
		}

		index = pString.find(pChar, index+1);
	}
	return index;
}

bool Tokenizer::isRestringedChar(char pChar){
	int length = (sizeof _restringedChars )/(sizeof(char));
	for (int i = 0; i < length; i++){
		if (pChar == _restringedChars[i]){
			return true;
		}
	}
	return false;
}

std::string Tokenizer::cleanEntry(std::string pEntry){
	std::string buffer;
	for (int i = 0; i < pEntry.length(); i++){
		if ( !isRestringedChar(pEntry[i]) ){
			buffer += pEntry[i];
		}
	}
	return buffer;
}

std::string Tokenizer::getParameters(std::string pMessage){
	int start = pMessage.find(" ") + 1;
	if (start != 0){
		return pMessage.substr(start, pMessage.length() - start);
	} else {
		return "";
	}
}

std::string Tokenizer::getCommandSpace(std::string pString, int pNumber){
	int start = 0;
	int final = -1;
	for (; pNumber > 0; pNumber--){
		start = final+1;
		if (pString[start] == '"'){
			final = pString.find('"', start+1) + 1;
		} else {
			final = pString.find(' ', start+1);
		}
		if (final == -1 && pNumber > 1){
			return "";
		}
	}
	return pString.substr(start, final-start);
}

std::string Tokenizer::getRegister(std::string pRegisters, int pRegNum){
	int prevSemicolon = charIndex(pRegisters, ';', pRegNum-1);
	int nextSemicolon = charIndex(pRegisters, ';', pRegNum);

	return pRegisters.substr(prevSemicolon+1, nextSemicolon - prevSemicolon -1);

}

std::string Tokenizer::getRegName(std::string pRegister){
	int final = charIndex(pRegister, '#', 1);
	return pRegister.substr(0, final);
}

std::string Tokenizer::getRegType(std::string pRegister){
	int start = charIndex(pRegister, '#', 1)+1;
	int final = charIndex(pRegister, '#', 2);
	return pRegister.substr(start, final-start);
}

std::string Tokenizer::getRegSize(std::string pRegister){
	int start = charIndex(pRegister, '#', 2)+1;
	return pRegister.substr(start, pRegister.length()-start);
}
