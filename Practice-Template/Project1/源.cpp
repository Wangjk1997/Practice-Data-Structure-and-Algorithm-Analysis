/*通过一个简单的交换函数联系函数模板*/
#include<iostream >
#include<string>
using std::cout;
using std::string;
using std::endl;
template <typename T>
void swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	string str1 = "wang";
	string str2 = "junkai";
	swap(str1, str2);
	int a = 1;
	int b = 2;
	swap(a, b);
	cout << str1 << endl << str2 << endl;
	cout << a << endl<<b << endl;
	return 0;
}