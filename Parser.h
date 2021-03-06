#ifndef Parser_h
#define Parser_h
#include"sysfunc.h"
#include"Request.h"

/*
PARSES REQUEST FROM CLIENT
e.g:
Request b;
RequestParser a(message);
if(a.is_success())b=a.get();
*/

//next position before the next \r\n
int parse_line(string &message,int current);
class RequestParser {
	string message;
	bool fail_flag;
	Request *result;
	int current;//scanner flag

	bool parse();
public:
	RequestParser(string &m) :message(m) { current = 0, result = 0; fail_flag = parse(); }
	bool is_success() { return !fail_flag; }
	Request *get() { if (fail_flag||result==0)return nullptr; return result; }//...is there a better way?
};

/*
PARSES RESPONSE FROM SERVER
temporily not needed
let it rest in the TODOlist
*/
#include<iostream>
using namespace std;
class ResponseParser{
	string message;
	bool fail_flag;
	Response *result;
	int current;//scanner
	
	bool parse();
public:
	ResponseParser(string &m) :message(m) {result=0,current=0; fail_flag=parse(); }
	bool is_success(){return !fail_flag;}
	Response *get(){ if (fail_flag||result==0)return nullptr; return result; }//... i cant think of one
};

#endif
