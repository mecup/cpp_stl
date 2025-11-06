/**
* replace() 算法会用新的值来替换和给定值相匹配的元素。它的前两个参数是被处理序列的正向迭代器，第 3 个参数是被替换的值，第 4 个参数是新的值。
* replace_if() 会将使谓词返回 true 的元素替换为新的值。它的第 3 个参数是一个谓词，第 4 个参数是新的值。
* replace_copy() 算法和 replace() 做的事是一样的，但它的结果会被保存到另一个序列中，而不会改变原始序列。它的前两个参数是输入序列的正向迭代器，第 3 个参数是输入序列的开始迭代器，最后两个参数分别是要被替换的值和替换值。
* replace_copy_if() 和 replace_if() 算法是相同的，但它的结果会被保存到另一个序列中。它的前两个参数是输入序列的迭代器，第 3 个参数是输出序列的开始迭代器，最后两个参数分别是谓词和替换值
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp (int n)
{
	return n % 2 == 0;
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
	cout << "================= replace =================" << endl;
	vector<int> v = {1, 2, 5, 4, 5, 6, 7, 5, 9, 10};
	replace(v.begin(), v.end(), 5, 500);
	printVector(v);
	
	cout << "================= replace_if =================" << endl;
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	replace_if(v.begin(), v.end(), cmp, 600);
	printVector(v);
	
	cout << "================= replace_copy =================" << endl;
	v = {1, 2, 5, 4, 5, 6, 7, 5, 9, 10};
	vector<int> v2(10);
	replace_copy(v.begin(), v.end(), v2.begin(), 5, 700);
	printVector(v2);
		
	cout << "================= replace_if_copy =================" << endl;
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v3(10);
	replace_copy_if(v.begin(), v.end(), v3.begin(), cmp, 800);
	printVector(v3);
	return 0;
}
