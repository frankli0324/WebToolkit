#include<iostream>
using namespace std;
#define DEBUG_PARSER

#ifdef DEBUG_REQUEST_RESPONSE
#include"Response.h"
#include"Request.h"
int main() {
	Response test1(Response_Status::OK);
	test1.set_content("Nothing");
	cout << test1.toString();

	Request test2(Request_Method::GET);
	test2.set_host("www.baidu.com");
	test2.set_target("home.html");
	test2.set_content("I want...");
	cout << endl << test2.toString();
	return 0;
}
#endif


#ifdef DEBUG_PARSER
#include"Parser.h"
void read(string &a) {
	string temp;
	while (getline(cin, temp))a +=temp+ "\r\n";
}
int main() {
	string a;
	read(a);
	Request *b=0;
	RequestParser test(a);
	if (test.is_success())b = test.get();
	cout << b->toString();
}
#endif