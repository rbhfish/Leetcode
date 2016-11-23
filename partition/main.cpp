#include <iostream>
#include <algorithm>
#include <vector>

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
	ListNode* partition(ListNode* list, int nTarget)
	{
		if(list == NULL)
			return NULL;
		
		ListNode dummy(-1);
		ListNode* llist = &dummy;
		ListNode* prev = list;
		
		ListNode bigDummy(-1);
		ListNode* blist = &bigDummy;
		
		while(prev)
		{
			int nTmp = prev->nValue;
			if(nTmp < nTarget)
			{
				llist->next = prev;
				llist = llist->next;
			}
			else
			{
				blist->next = prev;
				blist = blist->next;
			}
		
			prev = prev->next;
			if(prev == NULL)
			{
				blist->next = NULL;
				llist->next = bigDummy.next;
			}
		}
		return dummy.next;
	}
};
int main() {
	// your code goes here
	int nArray[] = {0,2,3,4,1,5,4,3,2,7,8,6,9};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode dummy(-1);
	ListNode* start = &dummy;
	for(int nIndex = 0; nIndex < nLen; ++nIndex)
	{
		start->next = new ListNode(nArray[nIndex]);
		start = start->next;
	}
	Solution A;
	dummy.next = A.partition(dummy.next,5);
	start = dummy.next;
	while(start)
	{
		cout<<start->nValue<<" ";
		start = start->next;
	}
	cout<<endl;
	return 0;
}