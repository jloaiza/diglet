#ifndef IFILE_H
#define IFILE_H

#include <string>
#include <iostream>

class iFile
{

private:

    int _diskID;
    std::string _name;
    std::string _user;
    int _regCount;
    int _startBlock;
    int _BlockSize;

public:

    bool operator==(std::string& pDiskID);
    bool operator!=(std::string& pDiskID);
    bool operator>=(std::string& pDiskID);
    bool operator>(std::string& pDiskID);
    bool operator<=(std::string& pDiskID);
    bool operator<(std::string& pDiskID);

    bool operator==(iFile& pDiskID);
    bool operator!=(iFile& pDiskID);
    bool operator>=(iFile& pDiskID);
    bool operator>(iFile& pDiskID);
    bool operator<=(iFile& pDiskID);
    bool operator<(iFile& pDiskID);


    /**
     * @brief iFile
     * @param pName
     * @param pDisk
     * @param pPointer
     */
    iFile(std::string pName, int pDisk, int pBlockSize);

    void addRegCount() {
        _regCount++;
    }

    void removeRegCount() {
        if (_regCount == 0){
            std::cout<<"Error. Removing more registers than posibles on "<<_name<<". Check algorithms.";
        }
        _regCount--;
    }

    /**
     * @brief getDisk
     * @return
     */
    int getDisk() const {
        return _diskID;
    }

    /**
     * @brief setDisk
     * @param pDisk
     */
    void setDisk(int pDisk){
        _diskID = pDisk;
    }

    /**
     * @brief getPointer
     * @return
     */
    int getStartBlock() const{
        return _startBlock;
    }

    /**
     * @brief setPointer
     * @param pPointer
     */
    void setStartBlock(int pBlock){
        _startBlock = pBlock;
    }
};

#endif // IFILE_H
