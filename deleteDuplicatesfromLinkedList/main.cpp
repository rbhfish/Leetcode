#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode
{
	int nValue;
	ListNode* next;
	ListNode(int x):nValue(x),next(NULL){};
};

class Solution
{
	public:
	ListNode* removeDuplicatesLinkedList(ListNode* list)
	{
		if(list == NULL || list->next == NULL)
			return list;
		
		ListNode dummy(-1);
		dummy.next = list;
		ListNode* prev = &dummy, *curPos = list, *endPos;
		int nFlag = 0;
		int bFlag = false;
		while(curPos)
		{
			int nCur = curPos->nValue;
			ListNode* nxtNode = curPos->next;
			if(nxtNode == NULL)
			{
				if(bFlag == true)
				{
					delete curPos;
					prev->next = NULL;
					break;
				}
				else
				{
					prev->next = curPos;
					break;
				}
			}
			else
			{
				int nNxt = nxtNode->nValue;
				int nCur = curPos->nValue;
				if(nCur == nNxt)
				{
					nFlag = nCur;	
					bFlag = true;
					delete curPos;
					curPos = nxtNode;
					prev->next = nxtNode;
				}
				else
				{
					if(bFlag)
					{
						bFlag = false;
						delete curPos;
						curPos = nxtNode;
						prev->next = nxtNode;
					}
					else
					{
						prev->next = curPos;
						prev = prev->next;
						curPos = nxtNode;
					}
				}
			}
		}
		return dummy.next;
	}
	ListNode* removeDuplicatesLinkedListII(ListNode* list)
	{
		if(list == NULL || list->next == NULL)
			return list;
		
		ListNode* nxtNode = list->next;
		if(list->nValue == nxtNode->nValue)
		{
			while(list->nValue == nxtNode->nValue)
			{
				ListNode* tmp = nxtNode->next?nxtNode->next:NULL;
				delete nxtNode;
				nxtNode = tmp;
				if(tmp == NULL)
					break;
			}
			delete list;
			return removeDuplicatesLinkedListII(nxtNode);
		}
		else
		{
			list->next = removeDuplicatesLinkedListII(nxtNode);
			return list;
		}
	}
};

int main() {
	// your code goes here
	int nArray[] = {0,0,0,0,1,1,2,2,2,2,3};
	int nLen = sizeof(nArray)/sizeof(int);
	ListNode dummy(-1);
	ListNode* list = &dummy;
	for(int nIndex = 0; nIndex < nLen; ++nIndex)
	{
		list->next = new ListNode(nArray[nIndex]);
		list = list->next;
	}
	Solution A;
	list = A.removeDuplicatesLinkedListII(dummy.next);
	if(list == NULL)
	{
		cout<<"There is no element!"<<endl;
	}
	else{
		while(list)
		{
			cout<<list->nValue<<" ";
			list = list->next;
		}
	}
	return 0;
}