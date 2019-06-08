#include "List_test.h"

void List_test()
{
	using std::cout;
	List<int> tst;
	cout <<"test size(): " << tst.size()<<"\n";
	int length = 10;
	for (int i = 0; i < length; i++)
	{
		tst.push_back(i);
	}
	for (List<int>::iterator itr = tst.begin(); itr != tst.end();)
	{
		cout << *itr << "\n";
		++itr;
	}
	tst.clear();
	cout << "now size"<< tst.size() << "\n";
}