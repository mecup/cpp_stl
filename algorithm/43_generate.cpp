/**
* generate 与 generate_n这两个算法如同一个"数据工厂"，它们通过一个生成器函数来创造数据，并填充到指定的容器范围内
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n = 0;
int func ()
{
	n = n+2;
	return n;
}

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
	cout << "========== generate ===========" << endl;
	vector<int> v(10); 
	generate(v.begin(), v.end(), func);
	printVector(v);
	
	cout << "========== generate_n ===========" << endl;
	vector<int> v2(10);
	generate_n(v2.begin(), 6, func);
	printVector(v2);
	return 0;
}
