/**
* find_end() �������������� A �в������� B ���һ�γ��ֵ�λ�á���ô�������֪������ B ������ A �е�һ�γ��ֵ�λ�ã������ʵ���أ����Խ��� search() ������
* search() �����Ĺ���ǡ�ú� find_end() �����෴������������ A �в������� B ��һ�γ��ֵ�λ��
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //���n1�ܽ�n2�������򷵻�true�����򷵻�false
{
	if (n1%n2==0) 
		return true;
	return false;
}

int main()
{
	/******************* Ĭ�Ϲ��� **********************/
	vector<int> v1 = {1, 2, 3, 4, 8, 12, 18, 1, 2, 3};
	vector<int> v2 = { 1, 2, 3 };
	auto it = search(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (it != v1.end())
		cout << "��һ��{1,2,3}����ʼλ��Ϊ��" << it - v1.begin() << ", *it = " << *it << endl;
	else 
		cout << "û���ҵ�����������������" << endl;	
	
	/******************* �Զ������ **********************/
	vector<int> v3 = {8, 64, 24, 12, 40, 34, 8, 12, 22, 44, 66};
	vector<int> v4 = { 2, 4, 6 };
	auto it2 = search(v3.begin(), v3.end(), v4.begin(), v4.end(), cmp);
	if (it2 != v3.end())
		cout << "��һ���ֱܷ� {2��4��6} �����е�������λ�ã�" << it2 - v3.begin() << ", *it2 = " << *it2 << endl;
	else 
		cout << "û���ҵ�����������������" << endl;
	cout << endl;
	return 0;
}
