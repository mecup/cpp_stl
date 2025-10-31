/**
* ��ĳЩ�����У�������Ҫ���� partition() ���� stable_partition() ���������顱�Ĺ��ܣ����������ԭ�������κ��޸ġ���������£��Ϳ��Կ���ʹ�� partition_copy() ������
* partition_copy() ����Ҳ�ܰ���ĳ��ɸѡ�����ָ�������ڵ����ݽ��С����顱�����ҷ���󲻻�ı����Ԫ�ص����λ�á�
* ����Ҫ���ǣ�partition_copy() ���������ԭ���н��б����������У������Ը��Ƶķ�ʽ�������и������ݡ����顱��������ָ��λ�ô洢��
* 
* partition_copy() ��������һ�� pair ����ֵ������� 2 ������������һ��������ָ����ǵ�һ���������һ��Ԫ��֮���λ�ã��ڶ���������ָ����ǵڶ����������һ��Ԫ��֮���λ��
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
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	vector<int> oushu(10); //�洢ż��
	vector<int> jishu(10); //�洢����
	/******************* partition_copy **********************/
	auto result = partition_copy(v.begin(), v.end(), oushu.begin(), jishu.begin(), cmp);
	cout << "ż�����֣�";
	for (auto it = oushu.begin(); it != result.first; it++) //ע��۲��ӡ��Χ�����ﵽ����
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "��ż�����֣�";
	for (auto it = jishu.begin(); it != result.second; it++) //ע��۲��ӡ��Χ�����ﵽ����
	{
		cout << *it << " ";
	}
	cout << endl;
}
