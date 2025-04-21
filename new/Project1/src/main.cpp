/*
* 
*/
#include<iostream>
using namespace std;
int main()
{
	int _id = 0;
	int itr1 = 0, itr2 = 0;
	char first_name[100] = { '\0' }, second_name[100] = { '\0' };
	for (int itr2 = 0;itr2 < 10;itr2++)
	{
		cout << itr2 << endl;
	}
	cout << itr2 << endl;
	strcat(first_name, "sneha");
	cout << first_name << endl;
	bool flag = true;
	cout << flag << endl;
	{
		cout << &first_name;
	}
	flag = false;
	cout << flag << endl;
	return 0;
}