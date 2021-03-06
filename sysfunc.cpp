#include"sysfunc.h"
void swap(char &a,char &b) {
	a = a ^ b; b = a ^ b; a = a ^ b;
}
char *toStr(int i) {
	char *a = new char[20];
	int num = 0;
	while (i)
		a[num++] = (i % 10) + 48, i /= 10;
	for (int i = 0; i < num / 2; i++)
		swap(a[i], a[num - i - 1]);
	a[num] = 0;
	return a;
}

string tidy(string a) {
	int head = 0, tail = a.length() - 1;
	while (a[head++] == ' ');
	while (a[tail--] == ' ');
	a = a.substr(head, tail - head + 1);
	return a;
}
