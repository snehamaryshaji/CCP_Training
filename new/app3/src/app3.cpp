// app3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <add.h>
#include <sub.h>
#include <mul.h>
#include <dev.h>
//int add(int, int);
int main()
{
    int a , b;
    char op;
    cout << "enter 2 numbers" << endl;
    cin >> a >> b;
    cout << "enter the operator" << endl;
   cin>>op;
   switch (op)
   {
   case '+':
       cout << "result=" << add(a, b);
       //cout << "result=" << res;
       break;
   case '-':
       cout << "result=" << sub(a, b);
       //cout <<"result="<<var;
       break;
   case '*':
       cout << "result=" << mul(a, b);
       //cout <<"result="<<var;
       break;

   case '/':
       cout << "result=" << dev(a, b);
       //cout <<"result="<<var;
       break;
   default:
       cout << "invalid oparator" << endl;
       //break;
   }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
