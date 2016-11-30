#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool implementMatchFunc(const char* pcInput, const char* pChar)
	{
		if(pcInput == NULL || pChar == NULL)
			return false;
		
		if(*pChar == '\0')
			return *pcInput == '\0';
			
		if(*(pChar+1) != '*')
		{
			if(*pChar == *pcInput || (*pChar == '.' && *pcInput != '\0') )
			{
				pcInput++;
				pChar++;
				return implementMatchFunc(pcInput,pChar);
			}
			else
				return false;
		}
		else
		{
			while(*pChar == *pcInput || (*pChar == '.' && *pcInput != '\0'))
			{
				if(implementMatchFunc(pcInput,pChar+ 2))
				{
					return true;
				}
				pcInput++;
			}
			return implementMatchFunc(pcInput,pChar+ 2);
		}
	}
};

int main() {
	// your code goes here
	return 0;
}