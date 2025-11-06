/**
* equal() 算法可以告诉我们两个序列是否匹配。mismatch() 算法也可以告诉我们两个序列是否匹配，而且如果不匹配，它还能告诉我们不匹配的位置。
* mismatch() 返回一个pair，pair 包含的迭代器指向第一对不匹配的元素。如果完全匹配，那么pair返回的就是两个序列的end位置
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 4, 5, 5, 5, 9, 10, 21, 40, 60, 80}; 
	vector<int> v2 = {1, 2, 3, 4, 4, 5, 5, 5, 9, 10, 21, 40, 60, 80, 90}; 
	auto it = mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (it.first == v1.end() && it.second == v2.end())
	{
		cout << "v1 与 v2 内容完全相同" << endl;
		return 0;
	}
	cout << "v1 与 v2 内容的第一处差异出现在：" << endl;
	cout << "v1 的第" << (it.first - v1.begin()) << "个字符处，内容为：" << *it.first << endl; 
	cout << "v2 的第" << (it.second - v2.begin()) << "个字符处，内容为：" << *it.second << endl; 
	return 0;
}
