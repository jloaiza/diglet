#include "ifile.h"


iFile::iFile(std::string pName, std::string pDisk, int pBlockSize, RegisterSpace * pRegister)
{	
	_BlockSize = pBlockSize;
	name = pName;
    _diskID = pDisk;
    _Blocks = new SimpleList();	
    createMetadata(RegisterSpace *pRegister);
}

bool inline operator==(std::string& pDiskID){
    return _diskID == pDiskID
}

bool inline operator!=(std::string& pDiskID){
    return _diskID != pDiskID;
}

bool inline operator>=(std::string& pDiskID){
    return _diskID >= pDiskID;
}

bool inline operator>(std::string& pDiskID){
    return _diskID > pDiskID;
}

bool inline operator<=(std::string& pDiskID){
    return _diskID <= pDiskID;
}

bool inline operator<(std::string& pDiskID){
    return _diskID < pDiskID;
}

bool inline operator==(iFile& pDiskID){
    return _diskID == pDiskID.getID();
}

bool inline operator!=(iFile& pDiskID){
    return _diskID != pDiskID.getID();
}

bool inline operator>=(iFile& pDiskID){
    return _diskID >= pDiskID.getID();
}

bool inline operator>(iFile& pDiskID){
    return _diskID > pDiskID.getID();
}

bool inline operator<=(iFile& pDiskID){
    return _diskID <= pDiskID.getID();
}

bool inline operator<(iFile& pDiskID){
    return _diskID < pDiskID.getID();
}