#include "Vector_test.h"
void Vector_test(void)
{
	using namespace std;
	Vector<int> this_Vector(10);
	cout << this_Vector.size()<<"\n";
	int index = 0;
	for (Vector<int>::iterator itr = this_Vector.begin(); itr != this_Vector.end(); itr++)
	{
		*itr = index++;
	}
	for (Vector<int>::iterator itr = this_Vector.begin(); itr != this_Vector.end(); itr++)
	{
		cout << *itr << "\n";
	}
}