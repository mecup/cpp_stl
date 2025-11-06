/**
* transform() 可以将函数应用到序列的元素上，并将这个函数返回的值保存到另一个序列中，它返回的迭代器指向输出序列所保存的最后一个元素的下一个位置。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int func (int n)
{
	return n*10;
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
	string s = "Hello, World"; 
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << s << endl;
	
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	transform(v.begin(), v.end(), v.begin(), func);
	printVector(v);
	return 0;
}
