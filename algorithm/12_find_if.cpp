/**
* find_if() �������ڲ��ҷ���ν�ʺ�������ĵ�һ��Ԫ�أ��� find_if_not() ���������ڲ��ҵ�һ��������ν�ʺ��������Ԫ�ء�
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n) //�����ż���򷵻�true�����򷵻�false
{
	if (n%2==0) 
		return true;
	return false;
}

int main()
{
	/******************* find_if **********************/
	vector<int> v = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	auto it = find_if(v.begin(), v.end(), cmp);
	if (it != v.end())
		cout << "vector�е�һ��ż��Ϊ��" << *it << endl;
	else 
		cout << "find_ifû���ҵ�ż��" << endl;
	cout << endl;
	
	/******************* find_if_not **********************/
	int a[] = {8, 6, 14, 12, 40, 34, 8, 12, 28, 33, 39};
	v = vector<int>(a, a+11); //����תvector
	auto it2 = find_if_not(v.begin(), v.end(), cmp);
	if (it2 != v.end())
		cout << "vector�е�һ������ż��������Ϊ��" << *it2 << endl;
	else 
		cout << "find_ifû���ҵ���ż��" << endl;
	cout << endl;
	return 0;
}
