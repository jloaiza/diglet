#ifndef LSS
#define LSS

#include "../util/comparable.h"
#include <string>

class Lss : public Comparable {
	
private:
    const char* _disk;
	bool _busy;
	int _size;
	int _blockSize;
	short _id;
	std::string _secKey;
	char *read(int pPos, int pSize);
	void write(int pPos, int pSize, char* pData);
	void header();

public:    
    Lss(const char*  pDisk, short pID, int pSize, std::string pSecKey);
	void write(char* pText, int pBlock);
	char * read(int pBlock);
	int getFreeBlock();
	std::string getSecKey();
	void eraseBlock(int pBlock);
	int getBlockSize();
	void format(int pBlockSize);
	void write(char* pText, int pBlock, int pOffset, int pSize);
	char* read(int pBlock, int pOffset, int pSize);
	
	bool eql(Comparable* arg);
	bool gtr(Comparable* arg);
	bool lss(Comparable* arg);
	void print();

	bool operator != (const short& pToCompare);
	bool operator == (const short& pToCompare);
	bool operator < (const short& pToCompare);
	bool operator <= (const short& pToCompare);
	bool operator > (const short& pToCompare);
	bool operator >= (const short& pToCompare);

};

#endif
