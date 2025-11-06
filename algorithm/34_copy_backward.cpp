/**
* 像 copy() 那样复制元素，但是从最后一个元素开始复制，最后复制第一个元素。
* copy_backward() 会复制前两个迭代器参数指定的序列。第三个参数是目的序列的结束迭代器end（注意不是起始迭代器begin）
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
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	printVector(v);
	auto it = copy_backward(v.begin(), v.begin() + 8, v.end());
	printVector(v);
	cout << "copy返回的迭代器位置：" << it-v.begin() << endl;
	return 0;
}
