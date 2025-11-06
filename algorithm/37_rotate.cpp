/**
* 旋转容器中的元素序列
* rotate() 的第一个参数是这个序列的开始迭代器；第二个参数是指向新的第一个元素的迭代器，它必定在序列之内。第三个参数是这个序列的结束迭代器。
* 元素的圆形序列会被维持，因此可以有效地旋转元素环，直到新的第一个元素成为序列的开始。这个算法会返回一个迭代器，它指向原始的第一个元素所在的新位置。
* 
* 这个算法会返回一个迭代器，它指向原始的第一个元素所在的新位置。
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
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; 
	cout << "========== 原始vector ===========" << endl;
	printVector(v);
	cout << endl;
	cout << "========== 将第一个元素旋转到begin的附近 ===========" << endl;
	auto it = rotate(v.begin(), v.begin() + 2, v.end());
	printVector(v);
	cout << "旋转后，原始的第一个元素所在的新位置：" << it-v.begin() << endl << endl;
	
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; 
	cout << "========== 将第一个元素旋转到end的附近 ===========" << endl;
	it = rotate(v.begin(), v.end() - 2, v.end());
	printVector(v);
	cout << "旋转后，原始的第一个元素所在的新位置：" << it-v.begin() << endl << endl;
	return 0;
}
