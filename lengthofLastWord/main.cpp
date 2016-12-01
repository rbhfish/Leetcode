#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int theLengthofLastWord(const char* pChar)
	{
		if(pChar == NULL)
			return -1;
			
		char *pEmpty = NULL;
		char* head = (char*)pChar;
		int nLen = 0;
		
		while(*head != '\0')
		{
			if(*head ==' ')
				pEmpty = head;
				
			head++;
		}
		nLen = head - pEmpty - 1;
		return nLen;
	}
};

int main() {
	// your code goes here
	string str = "I am the one who loves you most";
	Solution A;
	int nLen = A.theLengthofLastWord(str.c_str());
	cout<<"the length of the last word is "<<nLen<<endl;
	return 0;
}