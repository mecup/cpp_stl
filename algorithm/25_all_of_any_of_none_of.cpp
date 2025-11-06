/**
* all_of() 算法会返回 true，前提是序列中的所有元素都可以使谓词返回 true。
* any_of() 算法会返回 true，前提是序列中的任意一个元素都可以使谓词返回 true。
* none_of() 算法会返回 true，前提是序列中没有元素可以使谓词返回 true。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int n)
{
	return n > 10;
}

int main()
{
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	bool isAll = all_of(v.begin(), v.end(), cmp);
	cout << "所有元素都大于10：" << (isAll?"是":"否") << endl;
	bool isAny = any_of(v.begin(), v.end(), cmp);
	cout << "至少有一个元素大于10：" << (isAny?"是":"否") << endl;
	bool isNone = none_of(v.begin(), v.end(), cmp);
	cout << "没有元素大于10：" << (isNone?"是":"否") << endl;
	return 0;
}
