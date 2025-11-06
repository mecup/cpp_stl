/**
* copy_if() 算法可以从源序列复制使谓词返回 true 的元素，所以可以把它看作一个过滤器。
* 前两个参数定义源序列的输入迭代器，第三个参数是指向目的序列的第一个位置的输出迭代器，第 4 个参数是一个谓词。
* 函数会返回一个输出迭代器，它指向最后一个被复制元素的下一个位置。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//是偶数返回true，否则返回false
bool cmp(int n)
{
	return n%2 == 0;
}

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
	copy_if(v2.begin(), v2.end(), v1.begin() + 3, cmp);
	printVector(v1);
	return 0;
}
