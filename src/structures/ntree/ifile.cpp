#include "ifile.h"

iFile::iFile(std::string pName, int pDisk, int pPointer){

    name = pName;
    _diskID = pDisk;
    _startBlock = pPointer;

}


int iFile::getDisk(){
    return _diskID;
}

void iFile::setDisk(int pDisk){
    _diskID = pDisk;
}

int iFile::getStartBlock(){
    return _startBlock;
}

void iFile::setStartBlock(int pPointer){
    _startBlock = pPointer;
}

/** COMPARABLE INHERITANCE **/

bool iFile::eql(Comparable* arg){

    /** TODO **/
    return false;

}

bool iFile::gtr(Comparable *arg){

    /** TODO **/
    return false;

}

bool iFile::lss(Comparable *arg){

    /** TODO **/
    return false;

}

void iFile::print(){
    /** TODO **/
}
