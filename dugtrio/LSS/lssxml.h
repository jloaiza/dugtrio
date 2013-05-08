#ifndef LSSXML
#define LSSXML

#include <string>

class LSS_XML{
public:

    /**
     * @brief isConnected
     * @param pIP
     * @param pID
     * @return
     */
	static bool isConnected(std::string pIP, int pID);

    /**
     * @brief rightSecurityKey
     * @param pID
     * @param pSecurityKey
     * @return
     */
	static bool rightSecurityKey(int pID, std::string pSecurityKey);

    /**
     * @brief connect
     * @param pIP
     * @param pID
     */
	static void connect(std::string pIP, int pID);

    /**
     * @brief release
     * @param pIP
     * @param pID
     */
	static void release(std::string pIP, int pID);

    /**
     * @brief checkXML
     */
	static void checkXML();

    /**
     * @brief addDisk
     * @param pID
     * @param pSecurityKey
     */
	static void addDisk(int pID, int pSecurityKey);

    /**
     * @brief eraseDisk
     * @param pID
     */
	static void eraseDisk(int pID);

    /**
     * @brief releaseAll
     */
	static void releaseAll();

private:

    /**
     * @brief createXML
     */
	static void createXML();
};

#endif /* LSSXML */
