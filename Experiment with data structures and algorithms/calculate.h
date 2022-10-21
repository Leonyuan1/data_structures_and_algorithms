double calculate(string want)
{
	stack<double>cal_stack;
	string a = " ";
	string b = "+-*/";
	string c = "0123456789";
	string temp_string;
	double result;
	int start, end;
	double h, j, k;
	for (int i = 0; i < want.length(); i = end)
	{
		start = i;
		end = want.find_first_of(a, i);
		if (end != -1)
		{
			temp_string = want.substr(start, end - start);
			int judge1;
			judge1 = temp_string.find_first_of(c, 0);
			if (judge1 != -1)//Êý×Ö
			{
				int len;
				len = temp_string.size() + 1;
				char* arr = new char[len];
				strcpy_s(arr, len, temp_string.c_str());
				double numble = stod(arr);
				cal_stack.push(numble);
			}
			else//ÔËËã·ûºÅ
			{
				if (temp_string == "+")
				{
					cout << temp_string << endl;
					h = cal_stack.top();
					cal_stack.pop();
					j = cal_stack.top();
					k = h + j;
					cal_stack.pop();
					cal_stack.push(k);
				}
				else if (temp_string == "-")
				{
					h = cal_stack.top();
					cal_stack.pop();
					j = cal_stack.top();
					k = j-h;
					cal_stack.pop();
					cal_stack.push(k);
				}
				else if (temp_string == "*")
				{
					h = cal_stack.top();
					cal_stack.pop();
					j = cal_stack.top();
					k = h * j;
					cal_stack.pop();
					cal_stack.push(k);
				}
				else if (temp_string == "/")
				{
					h = cal_stack.top();
					cal_stack.pop();
					j = cal_stack.top();
					k = j / k;
					cal_stack.pop();
					cal_stack.push(k);
				}

			}
			end++;
		}
	}
	result = cal_stack.top();
	return result;
}