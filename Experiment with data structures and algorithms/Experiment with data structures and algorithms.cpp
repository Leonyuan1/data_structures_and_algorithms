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
void use();

int main()
{
	cout << "************Welcome to the expression calculator************" << endl;
	cout << "************************************************************" << endl;
	cout << "************************************************************" << endl;
	cout << "************************************************************" << endl;
	cout << "Please enter the expression to evaluate quickly!" << endl;
	cout << "Please pay attention to the symbol specification and enjoy your use!" << endl;
	use();	
	cout << "************************************************************" << endl;
	cout << "************************************************************" << endl;
	cout << "************************************************************" << endl;
	cout << "************************************************************" << endl;
	cout << "************************************************************" << endl;
	cout << "*******Thank you for using the expression calculator********" << endl;
	return 0;
}

void use()
{
	string c;
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
		use();
	}
	else
	{
		changed_string = change(getstring);//转化为后缀表达式
		cout << "得到的后缀表达式：" << changed_string << endl;
	}
	double answer = calculate(changed_string);
	cout << " " << endl;
	cout <<"result:" << answer << endl;
	cout << " " << endl;
	cout << "如需继续使用请输入c清零！" << endl;
	cout << " " << endl;
	cin >> c;
	if (c == "c"||c=="C")
	{
		use();
	}
}