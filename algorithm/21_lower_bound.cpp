/**
* lower_bound() ����������ָ�������ڲ��Ҳ�С��Ŀ��ֵ�ĵ�һ��Ԫ�أ��ú��������������ź��������
* ����ָ���½�λ�õĵ�����
* 
* ע�⣺������˵�ġ����ź��򡱣�����Ҫ��������ȫ����ĳ�����������������������
* ������Ҫ�� [first, last) ������������ element<val������ comp(val, element��������Ԫ�ض�λ�ڲ�����Ԫ�ص�ǰ�棨���� element Ϊָ����Χ�ڵ�Ԫ�أ�
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 9, 8, 7, 6}; 
	auto bound = lower_bound(v.begin(), v.end(), 4);
	cout << "Ԫ��4���½�λ�ã�" << bound - v.begin();
	cout << endl;
	
	vector<int> v2 = {90, 100, 90, 80, 80, 80, 80, 40, 50, 9, 10, 9, 8, 7, 6}; 
	bound = lower_bound(v2.begin(), v2.end(), 80, greater<int>());
	cout << "Ԫ��80���½�λ�ã�" << bound - v2.begin();
	cout << endl;
	return 0;
}
