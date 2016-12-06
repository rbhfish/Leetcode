#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
	public:
	bool isValidParentheses(string strParent)
	{
		int nLen = strParent.length();
		if(nLen%2 != 0)
		{
			cout<<"Got it"<<endl;
			return false;
		}
		stack<string> stk;
		
		for(int nIndex = 0; nIndex < strParent.length(); ++nIndex)
		{
			string tmp(strParent,nIndex,1);
			if(tmp == "(" || tmp == "{" || tmp == "[")
			{
				stk.push(tmp);
			}
			else if(tmp == ")")
			{
				string ttmp = stk.top();
				if(ttmp == "(")
					stk.pop();
				else
					return false;
			}
			else if(tmp == "]")
			{
				string ttmp = stk.top();
				if(ttmp == "[")
					stk.pop();
				else
					return false;				
			}
			else if(tmp == "}")
			{
				string ttmp = stk.top();
				if(ttmp == "{")
					stk.pop();
				else
					return false;
			}
			else
				return false;
		}
		if(stk.empty())
			return true;
		else
			return false;
	}
};

int main() {
	// your code goes here
	string str = "{((())[])})";
	Solution A;
	bool bResult = A.isValidParentheses(str);
	if(bResult)
		cout<<"it is right"<<endl;
	else
		cout<<"it is wrong"<<endl;
	return 0;
}