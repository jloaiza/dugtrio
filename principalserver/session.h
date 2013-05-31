#ifndef SESSION
#define SESSION

#include <string>

class Session {
private:
	int _seek;
	//Diskgroup* _disk;
	//nTree* _filesTree;
	//nTreeNode* _currentNode;
	//RegisterList* _register;
	std::string _user;
	std::string _currentPath;
	bool _consoleMode;

public:
	Session(std::string pUser){
		_user = pUser;
		_currentPath = "/";
		_consoleMode = false;
	}
	int getSeek() const {
		return _seek;
	}

	void setSeek(int pSeek){
		_seek = pSeek;
	}

	bool isOnConsoleMode() const{
		return _consoleMode;
	}

	void setConsoleMode(bool pValue) {
		_consoleMode = pValue;
	}

	std::string getUser() const{
		return _user;
	}

	std::string getCurrentPath() const {
		return _currentPath;
	}

};


#endif /* SESSION */