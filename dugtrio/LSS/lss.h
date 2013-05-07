
/**
  VERSION: 1a
**/


#ifndef LSS_H
#define LSS_H


#include <fstream>

/** TODO: check that this fordward declaration will correctly work **/
class Databuffer;
class DataNode;

class LSS{

private:

    /**
     * @brief _disk
     * @brief _busy
     * @brief _id
     * @brief _inBuffer
     * @brief _outBuffers
     */
    std::fstream    _disk;
    bool            _busy;
    int             _id;
    Databuffer*     _inBuffer;
    Databuffer*     _outBuffer;

public:
    LSS();

    /**
     * @brief flush
     * @param pPointer
     * @return
     */
    int flush(int pPointer);

    /**
     * @brief write
     * @param pData
     * @param pSize
     */
    void write(void* pData, int pSize);

    /**
     * @brief read
     * @param pPointer
     * @param pSize
     * @return
     */
    DataNode* read(int pPointer, int pSize);

    /**
     * @brief erase
     * @param pStartBlock
     */
    void erase(int pStartBlock);
}

#endif // LSS_H
