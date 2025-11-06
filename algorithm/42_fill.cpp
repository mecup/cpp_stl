/**
* fill() 和 fill_n() 算法提供了一种为元素序列填入给定值的简单方式
* fill() 会填充整个序列； fill_n() 则以给定的迭代器为起始位置，为指定个数的元素设置值。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//打印vector的内容
void printVector(vector<int> vs)
{
	for(auto it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	cout << "========== fill ===========" << endl;
	vector<int> v(10); 
	fill(v.begin(), v.end(), 5);
	printVector(v);
	
	cout << "========== fill_n ===========" << endl;
	vector<int> v2(10);
	fill_n(v2.begin(), 6, 5);
	printVector(v2);
	return 0;
}
