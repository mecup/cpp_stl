/**
* adjacent_find() ����������ָ����Χ�ڲ��� 2 ��������ȵ�Ԫ��
* �ú����᷵��һ����������������������ҳɹ�ʱ���õ�����ָ������������Ԫ�صĵ� 1 ��Ԫ�أ����������ʧ�ܣ��õ�������ָ��end
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //����������ֵĸ�λ����ͬ���򷵻�true�����򷵻�false
{
	if (n1%10==n2%10) 
		return true;
	return false;
}

int main()
{
	/******************* Ĭ�Ϲ��� **********************/
	vector<int> v = {19, 7, 11, 15, 35, 35, 8, 12, 28, 33, 39};
	auto it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
		cout << "������ȵĵ�һ��Ԫ�أ�" << *it << endl;
	else 
		cout << "û���ҵ���Ĭ�Ϲ���" << endl;
	cout << endl;
	
	/******************* �Զ������ **********************/
	it = adjacent_find(v.begin(), v.end(), cmp);
	if (it != v.end())
		cout << "�����Զ�������������һ��Ԫ�أ�" << *it << endl;
	else 
		cout << "û���ҵ����Զ������" << endl;
	cout << endl;
	return 0;
}
