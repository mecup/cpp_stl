/**
* find_first_of() ������ A �����в��Һ� B ����������Ԫ����ƥ��ĵ�һ��Ԫ��
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //���n1������n2�򷵻�true�����򷵻�false
{
	if (n1%n2==0) 
		return true;
	return false;
}

int main()
{
	/******************* Ĭ�Ϲ����find_first_of **********************/
	vector<int> v1 = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	vector<int> v2 = {14, 15, 16};
	auto it = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (it != v1.end())
		cout << "v1Ԫ���е�һ����v2Ԫ����ͬ�ģ�" << *it << endl;
	else 
		cout << "find_first_of��v1��û���ҵ�����������Ԫ��" << endl;
	cout << endl;
	
	/******************* �Զ�������find_first_of **********************/
	vector<int> v3 = {8, 6, 14, 12, 40, 34, 8, 12, 28, 33, 39};
	vector<int> v4 = {11, 13};
	auto it2 = find_first_of(v3.begin(), v3.end(), v4.begin(), v4.end(), cmp);
	if (it2 != v3.end())
		cout << "v3Ԫ���е�һ����v4Ԫ���������ģ�" << *it2 << endl;
	else 
		cout << "find_first_of��v3��û���ҵ�����������Ԫ��" << endl;
	cout << endl;
	return 0;
}
