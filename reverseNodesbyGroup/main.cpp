#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int nValue;
	ListNode* next;
	ListNode(int x):nValue(x),next(NULL){ };
};
//might use stack
class Solution
{
	public:
	ListNode* reverseNodesinKGroup(ListNode* list, int nGroup)
	{
		if(list == NULL || nGroup < 2)
			return list;
		
		ListNode dummy(-1);
		dummy.next = list;
		ListNode* curPos = list;
		ListNode* nxtGroupStart = list;
		
		for(int nIndex = 0; nIndex < nGroup; ++nIndex)
		{
			if(nxtGroupStart != NULL)
				nxtGroupStart = nxtGroupStart->next;
			else
				return dummy.next;
		}
		
		ListNode* newNxtGStart = reverseNodesinKGroup(nxtGroupStart,nGroup);
		ListNode* prev = NULL;
		while(curPos != nxtGroupStart)
		{
			ListNode* nxtNode = curPos->next;
			curPos->next = prev?prev:newNxtGStart;
			prev = curPos;
			curPos = nxtNode;
		}
		
		return prev;
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,1,2,3,4,5};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode dummy(-1);
	int nGroup = 4;
	ListNode* cur = &dummy;
	for(int nIndex = 0; nIndex < nLen; nIndex++)
	{
		cur->next = new ListNode(nArray[nIndex]);
		cur = cur->next;
	}
	Solution A;
	cur = A.reverseNodesinKGroup(dummy.next,nGroup);
	dummy.next = cur;
	if(cur != NULL)
	{
		while(cur)
		{
			cout<<cur->nValue<<" ";
			cur = cur->next;
		}
	}
	else
	{
		cout<<"There is nothing"<<endl;
	}
	return 0;
}
