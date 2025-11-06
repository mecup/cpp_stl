/**
* prev_permutation() 会生成一个序列的重排列，它是所有可能的字典序中的上一个排列，默认使用 < 运算符来做这些事情。
* next_permutation() 是按照字典升序的方式生成的排列。当我们想以降序的方式生成排列时，可以使用 prev_permutation()。
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
	cout << "-----------从大到小-------------" << endl;
	vector<int> v = {2, 1, 3, 4}; 
	do 
	{
		printVector(v);
	}
	while(prev_permutation(v.begin(), v.end()));
	
	cout << "-------------------------------" << endl;
	printVector(v);
	return 0;
}
