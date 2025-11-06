/**
* unique() 算法可以在序列中原地移除重复的元素，这就要求被处理的序列必须是正向迭代器所指定的。
* 在移除重复元素后，它会返回一个正向迭代器作为新序列的结束迭代器。可以提供一个函数对象作为可选的第三个参数，这个参数会定义一个用来代替 == 比较元素的方法。
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
	vector<int> v = {1, 2, 3, 3, 5, 6, 6, 8, 9, 9, 0}; 
	printVector(v);
	auto it = unique(v.begin(), v.end());
	printVector(v);
	cout << "unique返回的迭代器位置：" << it-v.begin() << endl << endl;
	cout << "删除掉重复元素之后：" << endl;
	v.erase(it, v.end()); //删除重复元素
	printVector(v);
	return 0;
}
