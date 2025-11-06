/**
* next_permutation() 会生成一个序列的重排列，它是所有可能的字典序中的下一个排列，默认使用 < 运算符来做这些事情。
* 它的参数为定义序列的迭代器和一个返回布尔值的函数，这个函数在下一个排列大于上一个排列时返回 true，如果上一个排列是序列中最大的，它返回 false，所以会生成字典序最小的排列。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//打印vector的内容
void printVector(vector<int> v)
{
	for(auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	cout << "-----------从小到大-------------" << endl;
	vector<int> v = {2, 1, 3, 4}; 
	do 
	{
		printVector(v);
	}
	while(next_permutation(v.begin(), v.end()));
	
	cout << "-------------------------------" << endl;
	printVector(v);
	return 0;
}
