/**
* is_permutation() 算法可以用来检查一个序列是不是另一个序列的排列，如果是，会返回 true。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1 = {2, 1, 3, 4};
	vector<int> v2 = {4, 2, 3, 1};  
	vector<int> v3 = {4, 2, 5, 1};  
	
	bool ok = is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end());
	cout << "v2是v1的一个排列：" << (ok?"true":"false") << endl;
	
	ok = is_permutation(v1.begin(), v1.end(), v3.begin(), v3.end());
	cout << "v3是v1的一个排列：" << (ok?"true":"false") << endl;
	
	return 0;
}
