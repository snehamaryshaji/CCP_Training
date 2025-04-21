
#include<iostream>
using namespace std; 
/*class test
{
	mutable int counter;
public:
	void update()
		const{
		counter++;
		}
};
int fun(int a)
{
	static int temp = 1000;
	temp = temp + a;
	return temp;
}*/
int main()
	{
	//const int val = 34;
	//val = 2; //cant able to reassign value to const value
	//int r = 100;
	//int ret = fun(r);
	//cout << ret<<endl;
	//ret = fun(r);
	//cout << ret;
	int a = 10;
	float b = 17.9;
	float res = a + b;
	cout << "result =" << a + b << endl;
	char ch = 'k';
	char cd = 'j';
	cout << "value=" <<cd+ch<<endl;
	//explicit typecasting
	double price = 7.99;
	int gst = 5;
	int tax = 8;
	int total = (int)price + tax;
	//float result = (float)gst / (float)tax;
	float result = (float)gst /tax;
	cout << "value =" << result << endl;
	cout<<"tprice= "<<total<<endl;
	int x[] = { 10,7,8 };
	printf("%d",2[x]);
	int i;
	i = 0x10 + 010 + 10;
	printf(" % x", i);
		return 0;

	}