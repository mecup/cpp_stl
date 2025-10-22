/**
* 1、sort() 只对 array、vector、deque 这 3 个容器提供支持
* 2、对于指定区域内值相等的元素，sort() 函数无法保证它们的相对位置不发生改变
* 3、如果既要完成排序又要保证相等元素的相对位置，可以使用 stable_sort() 函数，它的使用方法与 sort() 相同
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student
{
	string name; //姓名
	int score; //分数
};
bool cmp(student stu1, student stu2)
{
	return stu1.score > stu2.score;
}

int main()
{
	/*************** 字符串升序排序 *****************/
	vector<string> vs = {"china", "usa", "japan", "germany", "france", "england", "india"};
	sort(vs.begin(), vs.end());
	cout << "字符串升序排列：";
	for (auto it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
		
	/*************** 数字降序排序 *****************/
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	sort(v.begin(), v.end(), greater<int>());
	cout << "数字降序排列：";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** 结构体自定义排序 *****************/
	vector<student> stus;
	student s1 = {"张三", 89};
	student s2 = {"李四", 92};
	student s3 = {"王二麻子", 77};
	student s4 = {"王五", 86};
	student s5 = {"赵六", 90};
	student s6 = {"刘大", 96};
	stus.push_back(s1);
	stus.push_back(s2);
	stus.push_back(s3);
	stus.push_back(s4);
	stus.push_back(s5);
	stus.push_back(s6);
	sort(stus.begin(), stus.end(), cmp);
	cout << "学生分数排名：" << endl;
	for (auto it = stus.begin(); it != stus.end(); it++)
	{
		cout << it->name << " " << it->score << endl;
	}
}
