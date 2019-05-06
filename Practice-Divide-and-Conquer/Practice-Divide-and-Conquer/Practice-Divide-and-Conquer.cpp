#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
int process(int a[], int length);
int max3(int a, int b, int c);
int main()
{
	int v[8] =
	{4, -3, 5, -2, -1, 2, 6, -2 };
	cout << process(v, 8);
	
	system("pause");
}
int process(int a[], int length)
{
	if (length == 1)
	{
		return a[0];
	}
	else
	{
		int i = 0;
		int* leftVector = new int[length / 2];
		int* rightVector = new int[length / 2];
		for (i = 0; i < length / 2; i++)
		{
			leftVector[i] = a[i];
		}
		for (i = length / 2; i < length / 2; i++)
		{
			rightVector[i] = a[i];
		}
		int leftResult = process(leftVector, length / 2);
		int RightResult = process(rightVector, length / 2);
		int leftSum = 0;
		int leftMaxSum = a[length / 2 - 1];
		int rightSum = 0;
		int rightMaxSum = a[length / 2];
		for (i = length / 2 - 1; i > 0; i--);
		{
			leftSum += a[i];
			if (leftSum > leftMaxSum)
			{
				leftMaxSum = leftSum;
			}
		}
		for (i = length / 2; i < length; i++)
		{
			rightSum += a[i];
			if (rightSum > rightMaxSum)
			{
				rightMaxSum = rightSum;
			}
		}
		delete []leftVector;
		delete []rightVector;
		return max3(leftResult, RightResult, leftMaxSum + rightMaxSum);
	}
}
int max3(int a, int b, int c)
{
	if (b > a)
	{
		a = b;
	}
	if (c > a)
	{
		a = c;
	}
	return a;
}