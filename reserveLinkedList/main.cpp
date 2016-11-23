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
	ListNode* reserveLinkedList(ListNode* list, int m, int n)
	{
		ListNode dummy(-1);
		if(list == NULL)
			return dummy.next;
		dummy.next = list;
			
		ListNode *prev = &dummy;
		ListNode *prev_m;
		ListNode *mNode;
		ListNode *prev_n;
		int nIndex = 0;
		
		while(prev != NULL)
		{
			if(nIndex == m)
			{
				prev_m = prev;
				mNode = prev->next;
			}
			else if(nIndex == n)
			{
				prev_n = prev;
				
				prev_m->next = prev_n->next;
				ListNode* nNode = prev_n->next;
				ListNode* tmp = nNode->next;
				nNode->next = mNode->next;
				prev_n->next = mNode;
				mNode->next = tmp;
				break;
			}
			
			if(prev != NULL)
				prev = prev->next;
			
			nIndex++;
		}
		return dummy.next;
	}
	ListNode* reserveLinkedListII(ListNode *list, int m, int n)
	{
		ListNode dummy(-1);
		if(list == NULL)
			return dummy.next;
		
		dummy.next = list;
		ListNode* prev_m, *mNode, *prev = &dummy, *curNode;
		
		for(int nIndex = 0; nIndex < m -1; nIndex++)
		{
			prev = prev->next;
		}
		prev_m = prev;
		mNode = prev->next;
		prev = mNode;
		curNode = mNode->next;
		for(int nIndex = m; nIndex < n ; ++nIndex)
		{
			prev->next = curNode->next;
			curNode->next = prev_m->next;
			prev_m->next = curNode;
			curNode = prev->next;
		}
		
		return dummy.next;
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,1,2,3,4,5,6,7,8,9};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode list(-1);
	ListNode* start = &list;
	
	for(int nIndex = 0; nIndex < nLen ; ++nIndex)
	{
		start->next = new ListNode(nArray[nIndex]);
		start = start->next;
	}
	Solution A;
	ListNode *result = A.reserveLinkedListII(list.next,4,5);
	if(result == NULL)
		cout<<"result is NULL"<<endl;
	while(result)
	{
		cout<<result->nValue<<" ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}