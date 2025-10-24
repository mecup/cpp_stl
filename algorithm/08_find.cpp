/**
* find() ����������ָ����Χ�ڲ��Һ�Ŀ��Ԫ��ֵ��ȵĵ�һ��Ԫ�ء�
* �ú����᷵��һ��������������� find() �������ҳɹ�ʱ����ָ������� [first, last) �����ڲ��ҵ��ĵ�һ��Ŀ��Ԫ�أ��������ʧ�ܣ���õ�������ָ��� last ��ͬ��
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	/******************* ��vector��find **********************/
	vector<int> v = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	auto it = find(v.begin(), v.end(), 15);
	if (it != v.end())
		cout << "��vector��find��" << *it << endl;
	else 
		cout << "��vector��findû���ҵ�" << endl;
	cout << endl;
	
	/******************* ��������find **********************/
	int a[] = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	int *pos = find(a, a+11, 15);
	cout << "��������find��" << *pos << endl;
	cout << endl;
	return 0;
}
