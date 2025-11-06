/**
* copy_n() 算法可以从源容器复制指定个数的元素到目的容器中。
* 第一个参数是指向第一个源元素的输入迭代器，第二个参数是需要复制的元素的个数，第三个参数是指向目的容器的第一个位置的迭代器。
* 这个算法会返回一个指向最后一个被复制元素的后一个位置的迭代器
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
	vector<int> v2 = {55, 55, 55, 55}; 
	copy_n(v2.begin(), v2.size(), v1.begin() + 3);
	printVector(v1);
	return 0;
}
