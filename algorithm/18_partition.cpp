/**
* partition ��ֱ��Ϊ�����顱��partition() �����ɸ����û��Զ����ɸѡ������������ָ�������ڴ洢�����ݣ�ʹ���Ϊ 2 �飬��һ��Ϊ����ɸѡ���������ݣ���һ��Ϊ������ɸѡ���������ݡ�
* partition() �����᷵��һ������������ָ��������������ݵķֽ�λ�ã���ȷ�е�˵��ָ����ǵڶ��������еĵ� 1 ��Ԫ�ء�
* stable_partition() �������Ա�֤��ָ��������������ɷ����ͬʱ�����ı������Ԫ�ص����λ�á�
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n) //�����ż������true�����򷵻�false
{
	return n%2==0;
}

int main()
{
	/******************* partition **********************/
	vector<int> v1 = {1, 9, 4, 9, 0, 3, 0, 3};
	auto mid = partition(v1.begin(), v1.end(), cmp);
	cout << "[partition]ż�����֣�";
	for (auto it = v1.begin(); it != mid; it++) //ע��۲��ӡ��Χ�����ﵽ����
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "[partition]��ż�����֣�";
	for (auto it = mid; it != v1.end(); it++) //ע��۲��ӡ��Χ�����ﵽ����
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/******************* stable_partition **********************/
	vector<int> v2 = {1, 9, 4, 9, 0, 3, 0, 3};
	mid = stable_partition(v2.begin(), v2.end(), cmp);
	cout << "[stable_partition]ż�����֣�";
	for (auto it = v2.begin(); it != mid; it++) //ע��۲��ӡ��Χ�����ﵽ����
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "[stable_partition]��ż�����֣�";
	for (auto it = mid; it != v2.end(); it++) //ע��۲��ӡ��Χ�����ﵽ����
	{
		cout << *it << " ";
	}
	cout << endl;
}
