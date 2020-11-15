#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

vector <string> myStr;

void createStrings(int current,string str)
{
	if (current == 10)
		myStr.push_back(str);
	else
	{
		string pos1, pos2, pos3;
		pos1 = str;
		pos1.append(1, current+'0');
		pos2 = str + "+";
		pos2.append(1, current+'0');
		pos3 = str + "-";
		pos3.append(1, current+'0');
		createStrings(current + 1, pos1);
		createStrings(current + 1, pos2);
		createStrings(current + 1, pos3);
	}
}

int main()
{
	createStrings(1,"");
	for (auto s : myStr)
	{
		int index = 0;
		int sum = 0;
		while (index < s.size())
		{
			int num = 0;
			switch (s[index])
			{
				case '+':	
							index++;
							while (index < s.size() && s[index] != '+' && s[index] != '-')
							{
								num = num * 10 + (s[index] - '0');
								index++;
							}
							sum += num;
							break;
				case '-':	
							index++;
							while (index < s.size() && s[index] != '+' && s[index] != '-')
							{
								num = num * 10 + (s[index] - '0');
								index++;
							}
							sum -= num;
							break;
				default:	while (index < s.size() && s[index] != '+' && s[index] != '-')
							{
								num = num * 10 + (s[index] - '0');
								index++;
							}
							sum += num;
			}
		}
		if (sum == 100)
			cout << s << endl;
	}
	return 0;
}