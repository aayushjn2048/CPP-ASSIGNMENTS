#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	cout << "Enter a number between 0 to 100: ";
	int num;
	cin >> num;
	if (num <= 59)
		cout << "Grade F" << endl;
	else if (num <= 69)
		cout << "Grade D" << endl;
	else if (num <= 79)
		cout << "Grade C" << endl;
	else if (num <= 89)
		cout << "Grade B" << endl;
	else if (num <= 100)
		cout << "Grade A" << endl;
	return 0;
}