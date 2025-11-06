/**
* 如果不知道具体的场景，即元素保存在什么样的容器中，是不能从序列中移除元素的。
* 因此，“移除元素的”算法也无法做到这一点，它们只会重写被选择的元素或者忽略复制的元素。移除操作不会改变被“移除”元素的序列的元素个数。

有 4 种移除算法：

remove() 可以从它的前两个正向迭代器参数指定的序列中移除和第三个参数相等的对象。
基本上每个元素都是通过用它后面的元素覆盖它来实现移除的。它会返回一个指向新的最后一个元素之后的位置的迭代器。

remove_copy() 可以将前两个正向迭代器参数指定的序列中的元素复制到第三个参数指定的目的序列中，并忽略和第 4 个参数相等的元素。
它返回一个指向最后一个被复制到目的序列的元素的后一个位置的迭代器。序列不能是重叠的。

remove_if() 可以从前两个正向迭代器指定的序列中移除能够使作为第三个参数的谓词返回 true 的元素。

remove_copy_if() 可以将前两个正向迭代器参数指定的序列中，能够使作为第 4 个参数的谓词返回 true 的元素，复制到第三个参数指定的目的序列中。
它返回一个指向最后一个被复制到目的序列的元素的后一个位置的迭代器。序列不能是重叠的。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//如果n小于6则返回true
int cmp(int n)
{
	return n<6;
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
	cout << "========== remove ===========" << endl;
	vector<int> v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12}; 
	auto it = remove(v.begin(), v.end(), 5);
	printVector(v);
	cout << "返回的it位置(v)：" << it - v.begin() << endl;
	
	cout << "========== remove_copy ===========" << endl;
	v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12}; 
	vector<int> v2(10);
	it = remove_copy(v.begin(), v.end(), v2.begin(), 5);
	printVector(v2);
	cout << "返回的it位置(v2)：" << it - v2.begin() << endl;
	
	cout << "========== remove_if ===========" << endl;
	v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12}; 
	it = remove_if(v.begin(), v.end(), cmp);
	printVector(v);
	cout << "返回的it位置(v)：" << it - v.begin() << endl;
	
	cout << "========== remove_copy_if ===========" << endl;
	v = {1, 2, 5, 4, 5, 5, 5, 8, 9, 10, 11, 12}; 
	vector<int> v3(10);
	it = remove_copy_if(v.begin(), v.end(), v3.begin(), cmp);
	printVector(v3);
	cout << "返回的it位置(v3)：" << it - v3.begin() << endl;
	return 0;
}
