#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string longestCommonPrefix(vector<string> vStr)
	{
		if(vStr.size() < 2)
			return vStr[0];
		
		string strResult(vStr[0]);
		int nLen = strResult.length();
		auto it = strResult.begin();
		for(int nIndex = 1; nIndex < vStr.size(); ++nIndex)
		{
			string tmpStr = vStr[nIndex];
			int tmpLen = (nLen > tmpStr.length())?tmpStr.length():nLen;
			int n = 0;
			for( ; n < tmpLen; ++n)
			{
				if(strResult[n] != tmpStr[n])
				{
					nLen = n;
					break;
				}
				nLen = n+1;
			}
			strResult.erase(it + nLen,strResult.end());
			cout<<nIndex<<" "<<tmpLen<<" "<<nLen<<" strResult is "<<strResult<<endl;
		}
		return strResult;
	}
};

int main() {
	// your code goes here
	vector<string> vStr;
	string str1("I am the one who loves you most");
	string str2("I am a one");
	string str3("I am the one who");
	vStr.push_back(str1);
	vStr.push_back(str2);
	vStr.push_back(str3);
	Solution A;
	string strResult = A.longestCommonPrefix(vStr);
	cout<<"the result is "<<strResult<<endl;
	return 0;
}