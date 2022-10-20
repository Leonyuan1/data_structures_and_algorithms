// Experiment with data structures and algorithms.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdlib.h>
#include<string>
#include<stack>
using namespace std;
#define MAXSIZE 100

//string change(string str)//转化为后缀表达式的函数
//{
//	AStack<char> s;
//
//
//
////操作数次序不变，运算符次序发生变化，同时去掉括号。
//	//	转换规则是：设立一个栈，存放运算符，首先栈为空，
//	//	从左到右扫描中缀表达式，若遇操作数，直接输出；
//
//	/*若遇运算符，则与栈顶比较，栈顶运算符级别比当前运算符级别低则进栈，否则退出栈顶元素并输出；
//		若遇左括号，进栈；若遇右括号，则一直退栈输出，直到退到左括号止。
//		当栈变成空时，输出的结果即为后缀表达式。*/
//}

////中缀表达式转后缀表达式函数
string change(const string getstring)
{
	stack <char> str_stack;
	int start, end;
	string tempstring;
	string ss = "+-*/%()";
	string want;
	for (int i = 0; i < getstring.length(); i = end)
	{
		start = i;
		end = getstring.find_first_of(ss, i);
		if (start == end)
		{
			tempstring = getstring.substr(start, 1);
			end = end + 1;
		}
		else
		{
			
			if (end == -1)
			{
				end = getstring.length();
			}
			tempstring = getstring.substr(start, end-start);
		}
		if (tempstring == "(")
		{
			char c = '(';
			str_stack.push(c);
		}
		else if (tempstring == ")")
		{
			while(str_stack.top() != '(')
			{
				want += str_stack.top();
				want += " ";
				str_stack.pop();
			}str_stack.pop();

		}
		else if ((tempstring == "*" )|| (tempstring == "/"))
		{
			while ((str_stack.empty() != true) && (str_stack.top() == '*' || str_stack.top() == '/'))
			{
				want += str_stack.top();
				want += " ";
				str_stack.pop();
			}
			char c = tempstring[0];
			str_stack.push(c);
		}
		else if ((tempstring == "+") || (tempstring == "-"))
		{
			while ((str_stack.empty() != true)&&(str_stack.top() != '('))
			{
				want += str_stack.top();
				want += " ";
				str_stack.pop();
			}
			char c = tempstring[0];
			str_stack.push(c);
		}
		else
		{
			want += tempstring;
			want += " ";
		}	
	}
	while (str_stack.empty() != true)
	{
		want += str_stack.top();
		want += " ";
		str_stack.pop();

	}
	return want;

}

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
	system("pause");
	return 0;
}