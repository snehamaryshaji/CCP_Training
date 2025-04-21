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
	/*int option;
	cout << "enter the option" << endl;
	cin >> option;
	switch (option)
	{
	default:
		cout << "incorrect option" << endl;
		break;
	case coffee:
		cout << "coffee " << endl;
		break;
	case strong_cofee:
		cout << " tou selected tea " << endl;
		break;
	case tea:
		cout << " you stea " << endl;
		break;
	case filter_coffee:
		cout << "tea " << endl;
		break;
	case milk:
		cout << "tea " << endl;
		break;
	}

	
}*/
	/*int amount;
	cout << "enter the amount in hand" << endl;
	cin >> amount;
	if (amount < 10)
	{
		cout << "please get more amount" << endl;
	}
	else if(amount>10 and amount<=50)
	{
		cout << "i can order snacks" << endl;
	}
	else if (amount > 50 and amount <= 100)
	{
		cout << "i can order roti" << endl;
	}
	else
	{
		cout << "i can order complete meals" << endl;
	}*/
	string gen;
	cout << "enter the genure" << endl;
	cin >> gen;
	if (gen[0] >= 48 && gen[0] <= 6)
	{
		cout << "cant be sart with numeric values" << endl;
		return 0;
	}
		if (gen.compare("action") == 0)
		{
			cout << "selected genure is action" << endl;
		}
		else if ((gen.compare("comedy") == 0) || gen.compare("Comedy") == 0)
		{
			cout << "selected genure is comedy" << endl;
		}
		else
		{
			cout << "error" << endl;
		}

	return 0;
}