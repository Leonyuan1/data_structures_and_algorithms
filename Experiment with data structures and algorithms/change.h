////操作数次序不变，运算符次序发生变化，同时去掉括号。
//	//	转换规则是：设立一个栈，存放运算符，首先栈为空，
//	//	从左到右扫描中缀表达式，若遇操作数，直接输出；
//
//	/*若遇运算符，则与栈顶比较，栈顶运算符级别比当前运算符级别低则进栈，否则退出栈顶元素并输出；
//		若遇左括号，进栈；若遇右括号，则一直退栈输出，直到退到左括号止。
//		当栈变成空时，输出的结果即为后缀表达式。*/
// 
////中缀表达式转后缀表达式函数

//调试优化：无法计算含有负数的表达式
string change(const string getstring)//中缀表达式转后缀表达式
{
	stack <char> str_stack;//用来存运算符的栈
	int start, end;//用来存处理的字段的始末
	string tempstring;//中间字符串
	string ss = "+-*/%()";//符号
	string want;
	for (int i = 0; i < getstring.length(); i = end)//扫描
	{
		start = i;
		end = getstring.find_first_of(ss, i);
		if (start == end)//字符
		{
			tempstring = getstring.substr(start, 1);
			end = end + 1;
		
			if (tempstring == "(")
			{
				char c = '(';
				str_stack.push(c);
			}
			else if (tempstring == ")")
			{
				while (str_stack.top() != '(')
				{
					want += str_stack.top();
					want += " ";
					str_stack.pop();
				}str_stack.pop();

			}
			else if ((tempstring == "*") || (tempstring == "/"))
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
			else if (tempstring == "+")
			{
				while ((str_stack.empty() != true) && (str_stack.top() != '('))
				{
					want += str_stack.top();
					want += " ";
					str_stack.pop();
				}
				char c = tempstring[0];
				str_stack.push(c);
			}
			else if (tempstring == "-")//由于减号有可能代表负数 故将该情况分开讨论
			{
				end = end - 1;
				if (end==0)
				{
					end = getstring.find_first_of(ss, 1);
					want += getstring.substr(start, end - start);
					want += " ";
				}
				else if (end >= 1)
				{
					string a1;
					int end1 = end;
					a1 = getstring.substr(end - 1, 1);
					if (a1 == "(")
					{
						end = getstring.find_first_of(ss, end + 1);
						want += getstring.substr(end1, end - end1);
						want += " ";
					}

					
				}
				else
				{
					while ((str_stack.empty() != true) && (str_stack.top() != '('))
					{
						want += str_stack.top();
						want += " ";
						str_stack.pop();
					}
					char c = tempstring[0];
					str_stack.push(c);
				}
			}
		
		}
		else//数字
		{

			if (end == -1)
			{
				end = getstring.length();
			}
			tempstring = getstring.substr(start, end - start);

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



