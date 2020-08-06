// 字符匹配，正则表达式 

//#error This file requires compiler and library support for the \
//ISO C++ 2011 standard. This support is currently experimental, and must be \
//enabled with the -std=c++11 or -std=gnu++11 compiler options.

#include <iostream>
#include <regex> 
using namespace std;

int main(){
	
	string str = "adf d";
	regex r("[a-z]+");
	cout << regex_match(str, r) << endl;
	

	return 0;
} 
 
