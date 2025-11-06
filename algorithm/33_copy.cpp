/**
* copy() 算法可以将元素从源序列复制到目标序列。
* 前两个参数定义源序列的输入迭代器，第三个参数是指向目的序列的第一个位置的输出迭代器
* 函数会返回一个输出迭代器，它指向最后一个被复制元素的下一个位置。
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
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	vector<int> v2 = {55, 66, 77, 88}; 
	auto it = copy(v2.begin(), v2.end(), v1.begin() + 3);
	printVector(v1);
	cout << "copy返回的迭代器指向的元素：" << *it << endl;
	return 0;
}
