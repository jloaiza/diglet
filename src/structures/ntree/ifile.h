#ifndef IFILE_H
#define IFILE_H

#include <string>
#include "../util/comparable.h"

class iFile : public Comparable
{

private:

    int _diskID;
    SimpleList * _Blocks;
    std::string _name;
    int _BlockSize;
    
    std::string createMetadata();

public:

    /**
     * @brief iFile
     * @param pName
     * @param pDisk
     * @param pPointer
     */
    iFile(std::string pName, int pDisk, int pBlockSize);

    /**
     * @brief getDisk
     * @return
     */
    int getDisk();

    /**
     * @brief setDisk
     * @param pDisk
     */
    void setDisk(int pDisk);

    /**
     * @brief getPointer
     * @return
     */
    int getStartBlock();

    /**
     * @brief setPointer
     * @param pPointer
     */
    void setStartBlock(int pPointer);

    /** INHERITANCE FROM COMPARABLE **/

    bool eql(Comparable* arg);
    bool gtr(Comparable* arg);
    bool lss(Comparable* arg);
    void print();

};

#endif // IFILE_H
