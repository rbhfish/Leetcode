#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isValidPalindrone(string str)
	{
		transform(str.begin(),str.end(),str.begin(),::tolower);
		string::iterator start = str.begin(), end = prev(str.end());
		
		while(start < end)
		{
			if(isalnum(*start) == false)
				start++;
			else if(isalnum(*end) == false)
				end--;
			else if(*start != *end)
				return false;
			else
			{
				start++;
				end--;
			}
		}
		return true;
	}
};

int main() {
	// your code goes here
	string str = "A is b b si A!";
	Solution A;
	bool bResult = A.isValidPalindrone(str);
	if(bResult)
		cout<<"The sentence is Valid Palindrone "<<endl;
	else
		cout<<"The sentence is not Valid Palindrone "<<endl;
	return 0;
}