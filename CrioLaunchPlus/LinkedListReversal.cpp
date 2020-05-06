#include<bits/stdc++.h>
using namespace std;
struct  ListNode
{
    long long int data;
    ListNode *next=NULL;
    ListNode(long long int data)
    {
        this->data=data;
    }
};

ListNode* insert(ListNode* head, long  long int val)
{
    if(head==NULL)
    {
        return new ListNode(val);
    }
    if(head!=NULL)
    {
        head->next=insert(head->next,val);
    }
    return head;
}

void printList(ListNode * head)
{
    ListNode* p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
ListNode* reverseList(ListNode* head, int k)
{
    stack<int> s;
    ListNode *curr=head,*q=head,*p=head;
    int count=k;
    while(count>0 && p!=NULL)
    {
        s.push(p->data);
        p=p->next;
        count--;
    }
    count=k;
    while(count>0 && q!=p && !s.empty())
    {
        q->data=s.top();
        s.pop();
        q=q->next;
        count--;
    }
    return p;
}
void solve(ListNode *head, vector<int> &A)
{
    ListNode *curr=head;
    for(auto &it: A)
    {
        curr=reverseList(curr,it);
        if(curr==NULL)
        {
            break;
        }
    }
    return ;
}



bool checkLoopList(ListNode *head)
{
    if(head == NULL ||head ->next ==NULL)
    {
        return false;
    }
    ListNode *fast = head->next;
    ListNode *slow = head;
    bool flag= true;
    while(slow != fast)
    {
        slow = slow->next;
        if(fast !=NULL && fast->next != NULL)
        {
            fast = fast->next->next;
        }
        else 
        {
            flag=false;
            break;
        }
    }
    return flag;
}
ListNode* returnElementsInLoop(ListNode *&head)
{
    if(head==NULL)
    {
        return NULL;
    }
    set<ListNode*> s;
    ListNode *newHead =NULL;
    ListNode *iter = NULL, *iter2 = NULL;
    iter = head;
    while(iter && s.find(iter)==s.end())
    {
        s.insert(iter);
        iter = iter->next;
    }
    iter2= iter;
    newHead = iter;
    while(iter2->next != iter)
    {
        iter2=iter2->next;
    } 
    iter2->next = NULL;
    return newHead;
}
void getEvenOddList(ListNode * head , ListNode *&even , ListNode *&odd, int  index)
{
    even=NULL;
    odd=NULL;
    ListNode *evenLast=NULL;
    ListNode *oddLast=NULL;
    ListNode *p=head;
    for(int count=index;p!=NULL;p=p->next,count++)
    {
        if(count%2==0)
        {
            if(even==NULL)
            {
                even=new ListNode(p->data);
                evenLast=even;
            }
            else{
                evenLast->next=new ListNode(p->data);
                evenLast=evenLast->next;
            }
        }
        else
        {
            if(odd==NULL)
            {
                odd=new ListNode(p->data);
                oddLast=odd;
            }
            else
            {
                oddLast->next=new ListNode(p->data);
                oddLast=oddLast->next;
            }
            
        }
        
    }

}
int getIndex(ListNode *head, ListNode *loopHead)
{
    ListNode *p=head;
    int count=1;
    while(p!=loopHead)
    {
        p=p->next;
        count++;
    }
    return count;
}
vector<ListNode*> splitLinkedList(ListNode  *head)
{
    vector<ListNode*> soln;
    if(head==NULL)
    {
        soln.push_back(NULL);
        soln.push_back(NULL);
        return soln;
    }
    ListNode *odd=NULL,*even=NULL,*loopList=NULL;
    int  loop = checkLoopList(head);
    //cout<<"Ans :) "<<loop<<endl;
    if(loop == true)
    {
        loopList = returnElementsInLoop(head);
        int index=getIndex(head,loopList);
       // cout<<"Index :) "<<index;
        getEvenOddList(loopList,even, odd, index);
    }
    else
    {
        getEvenOddList(head,even,odd,1);
    }
    soln.push_back(odd);
    soln.push_back(even);
    return soln;
}
int main()
{
    int n,k;
    long long int val;
    ListNode* head=NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        head=insert(head,val);
    }
    cin>>k;
    ListNode *start=NULL;
    if(k>-1)
    {
        start=head;
        for(int i=1;i<k;i++)
        {
            start=start->next;
        }
    }
    ListNode *p=head;
    while(p&&p->next!=NULL)
    {
        p=p->next;
    }
   // p->next  = start;
    vector<ListNode*> ans = splitLinkedList(head);
    printList(ans[0]);
    printList(ans[1]);
    
    
    /*cout<<"Check for Loop :)" << checkLoopList(head)<<endl;
    ListNode *loopList = returnElementsInLoop(head);
    ListNode *even=NULL,*odd=NULL;
    getEvenOddList(loopList,even,odd);
    printList(even);
    printList(odd);
    //printList(loopList);
    cin>>k;
    vector<int> R(k);
    for(auto &it : R)
    {
        cin>>it;
    }
    printList(head);*/
    return 0;
}