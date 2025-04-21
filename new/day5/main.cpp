#include<iostream>
using namespace std;
enum genre {
	action,
	comedy,
	thriller
};
enum language
{
	english=1,//it will starts from 1
	hindi,
	tamil,
	telugu,
	malayalam
};
int main()
{
	int inplang;
	int inpgenr;
	cout << "enter which language" << endl;
	cout << "choosed genure is action" << endl;
	cin >> inplang;
	switch (inplang)
	{
	case english:
		cout << "you have chosen english" << endl;
		cout << "enter the genure" << endl;
		cin >> inpgenr;
		switch (inpgenr)
		{
		default:
			cout << "no value found" << endl;
			break;
		case action: //a name given to an integer value
			cout << "choosed genure is action" << endl;
			break;
		case comedy:
			cout << "choosed genure is comedy" << endl;
			break;
		case thriller:
			cout << "choosed genure is thriller" << endl;
			break;
		};
		break;
	case hindi:
		cout << "you have chosen hindi" << endl;
		cout << "enter the genure" << endl;
		cin >> inpgenr;
		switch (inpgenr)
		{
		default:
			cout << "no value found" << endl;
			break;
		case action: //a name given to an integer value
			cout << "choosed genure is action" << endl;
			break;
		case comedy:
			cout << "choosed genure is comedy" << endl;
			break;
		case thriller:
			cout << "choosed genure is thriller" << endl;
			break;
		};
		break;
	}
	return 0;
}
