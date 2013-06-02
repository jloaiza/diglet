
#include "ntree.h"
#include "ntreenode.h"

nTree::nTree(){

    _head = new nTreeNode(0, "/");
}

void nTree::insert(std::string pName, iFile *pFile, std::string pPath){

    nTreeNode* newNode = new nTreeNode(pFile, pName);

    /** Jugar con el path para encontrar donde insertarlo **/
    /** Absoluto o relativo?: Absoluto **/



}

void nTree::erase(std::string pPath){
    /** TODO **/
    
}

nTreeNode* nTree::getHead(){
    return _head;
}

nTreeNode* nTree::getNode(std::string pPath){
    /** TODO **/
    return 0;
}


