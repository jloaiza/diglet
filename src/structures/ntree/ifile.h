#ifndef IFILE_H
#define IFILE_H

#include <string>
#include "../comparable.h"

class iFile : public Comparable
{

private:

    int _diskID;
    int _startBlock;

public:

    /**
     * @brief iFile
     * @param pName
     * @param pDisk
     * @param pPointer
     */
    iFile(std::string pName, int pDisk, int pPointer);

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
