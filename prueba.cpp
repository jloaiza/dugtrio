#include <string>
#include <iostream>

int main(){

	std::string m = "touch /home/joseph/dugtrio -f nombre#1#32;edad#0#4";
	std::cout<<m.find(' ')<<std::endl;
	std::cout<<m.substr(0, m.find(' '))<<std::endl;
	return 0;
}