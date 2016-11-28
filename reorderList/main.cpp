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

class Solution
{
	public:
	ListNode* reorderList(ListNode* list)
	{
		if(list == NULL || list->next == NULL)
			return list;
			
		ListNode dummy(-1);
		dummy.next = list;
		ListNode* rear = NULL, *newList = &dummy, *prev = NULL;
		int nIndex = 0;
		while(list)
		{
			list = list->next;
			nIndex++;
		}
		list = dummy.next;
		int nMid = ((nIndex % 2) == 0)?(nIndex/2):(nIndex/2 + 1);
		
		for(int n = 0; n < nMid; ++n)
		{
			if(n == nMid - 1)
			{
				prev = list;
			}
			list = list->next;
		}

		rear  = list;

		prev->next = NULL;
		list = dummy.next;

		rear = reverseList(rear);

		while(list)
		{

			ListNode* nxtNode = list->next;
			ListNode* rnxtNode = (rear != NULL)?rear->next:NULL;
			
			newList->next = list;
			newList = newList->next;
			if(rear != NULL)
			{
				newList->next = rear;
				newList = newList->next;
			}
			else
			{
				newList->next = NULL;
				break;
			}
			list = nxtNode;
			rear = rnxtNode;
			
		}
		
		return dummy.next;
	}
	ListNode* reverseList(ListNode* list)
	{
		if(list == NULL || list->next == NULL)
			return list;
		
		ListNode* curPos = list, *prev = NULL;
		
		while(curPos)
		{
			ListNode* nxtNode = curPos->next;
			curPos->next = prev;
			prev = curPos;
			curPos = nxtNode;
		}
		return prev;
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,1,2,3,4,5,6,7,8,9,10};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode dummy(-1);
	ListNode* cur = &dummy;
	for(int nIndex = 0; nIndex < nLen; ++nIndex)
	{
		cur->next = new ListNode(nArray[nIndex]);
		cur = cur->next;
	}
	Solution A;
	cur = A.reorderList(dummy.next);
	if(cur == NULL)
		cout<<"There is no list"<<endl;
	else
	{
		while(cur)
		{
			cout<<cur->nValue<<" ";
			cur = cur->next;
		}
	}
	return 0;
}