#include<iostream>
#include"string.h"
using namespace std;

int main(int argc,char *argv[])//char **argv[]
{
	//stringhandling();
	//enumhand();
	cout<<"number of arguments" << argc << endl;
	cout << "argv[0]= " << argv[0] << endl;
	cout << "argv[1]= " << argv[1] << endl;
	int res = atoi(argv[1]) + atoi(argv[2]);
	cout << "result= " << res << endl;
	return 0;
    
    /*int main(int argc, char* argv[])
    {
        char arr = argv[2][0];

        switch (arr )
        {
        case '+':
            cout << "result= " << atoi(argv[1])+atoi(argv[3]);
            break;
        case '-':
            cout << "result= " << atoi(argv[1]) - atoi(argv[3]);
                break;
        case '*':
            cout << "result= " << atoi(argv[1]) * atoi(argv[3]);
            //cout <<"result="<<var;
            break;

        case '/':
            cout << "result= " << atoi(argv[1]) / atoi(argv[3]);
            //cout <<"result="<<var;
            break;
        default:
            cout << "invalid oparator" << endl;
            //break;
        }
        */
}
