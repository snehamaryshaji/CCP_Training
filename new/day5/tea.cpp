#include<iostream>
using namespace std;
enum genre {
	coffee,
	tea,
	strong_cofee,
    filter_coffee,
	milk
};
int main()
{
	int option;
	cout << "enter the option" << endl;
	switch (option)
	{
	default:
		cout << "incorrect option" << endl;
		break;
	case coffee:
		cout << "coffee " << endl;
		break;
	case strong_cofee:
		cout << "tea " << endl;
		break;
	case tea:
		cout << "tea " << endl;
		break;
	case filter_coffee:
		cout << "tea " << endl;
		break;
	case milk:
		cout << "tea " << endl;
		break;
	}

	return 0;
}