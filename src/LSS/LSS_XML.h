#ifndef LSSXML
#define LSSXML

#include <string>

class LSS_XML{
public:
	static bool isConnected(std::string pIP, int pID);
	static bool rightSecurityKey(int pID, std::string pSecurityKey);
	static void connect(std::string pIP, int pID);
	static void release(std::string pIP, int pID);
	static void checkXML();
	static void addDisk(int pID, int pSecurityKey);
	static void eraseDisk(int pID);
	static void releaseAll();

private:
	static void createXML();
};


#endif /* LSSXML */