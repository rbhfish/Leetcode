#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
	public:
	//the string started with '/'
	string implementSimplyPath(string strPath)
	{
		if(strPath.size() < 1)
			return NULL;
		
		stack<string> stackPath;
		string strResult;
		auto it = strPath.begin();
		while(it != strPath.end() )
		{
			auto tmp = find(it,strPath.end(),'/');
			if(tmp != strPath.end())
			{
				while(*tmp == '/')
					++tmp;
				auto start = tmp - 1;
				if(*tmp == '.')
				{
					++tmp;
					if(*tmp++ == '.' && *tmp == '/' && !stackPath.empty())
					{
						stackPath.pop();
					}
					it = tmp;
				}
				else if(tmp == strPath.end())
					break;
				else
				{
					auto nxt = find(tmp,strPath.end(),'/');
					//auto end = nxt - 1;
					string strTmp(start,nxt);
					stackPath.push(strTmp);
					it = nxt;
				}
			}
		}
		while(!stackPath.empty())
		{
			strResult = stackPath.top() + strResult;
			stackPath.pop();
		}
		//reverse(strResult.begin(), strResult.end());
		return strResult;
	}
};
int main() {
	// your code goes here
	string str = "/a/b/////////../../c/bb";
	Solution A;
	string result = A.implementSimplyPath(str);
	cout<<result<<endl;
	return 0;
}