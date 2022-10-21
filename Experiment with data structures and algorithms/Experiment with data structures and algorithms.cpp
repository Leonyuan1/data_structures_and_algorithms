// Experiment with data structures and algorithms.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdlib.h>
#include<string>
#include<stack>
using namespace std;
#define MAXSIZE 100
#include"calculate.h"
#include"change.h"


int main()
{
	string s = "0123456789+-*/%().";
	string getstring;//用户输入表达式字符串
	string changed_string;//得到的后缀表达式
	cout << "请输入你要计算的表达式：" << endl;
	cin >> getstring;
	int a;
	a = getstring.find_first_of(s, 0);
	if (a == -1)
	{
		cout << "error!!!" << endl;
	}
	else
	{
		changed_string = change(getstring);//转化为后缀表达式
		cout << changed_string << endl;
	}
	double answer = calculate(changed_string);
	cout << answer << endl;
	system("pause");
	return 0;
}