#include<iostream>
#include"string.h"
#include<cstring>
using namespace std;
void stringhandling()
{
	char ch = 'a';
	char fname[20];//array of char size is fixed
	string sname;//dynamically allocating
	cout << "ch value " << ch << endl;
	cout << "enter first name" << endl;
	cin >> fname;
	cout << "enter second name" << endl;
	cin >> sname;
	cout<<"my name is \n" << fname << "\r" << sname << endl;
	cout << "my name is \n" << fname << "\b" << sname << endl;
	cout << "my name is \n" << fname << "\a" << sname << endl;
	char name[] = "hello";
	cout<<"size " << sizeof(name) << endl;//it include null char
	cout << "length " << strlen(name) << endl;
	for (int i = 0;i < sizeof(name);i++)
	//for (int i = 0;i < 20;i++)
	{
		printf(" %c = %d", name[i],name[i]);
		cout <<" "<< endl;
	}

}
void enumhand()
	{
	//enum day { sunday, monday, teusday };
	//enum day { sunday=3000, monday, teusday ,wednesday,friday,saturday};
	enum day { sunday = 3000, monday, teusday, wednesday, friday=5, saturday };
	day today = teusday;
	cout << "today date= " << today << endl;
	}

