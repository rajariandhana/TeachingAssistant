//made by Ralfazza Rajariandhana with help of google and others
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f1(i,bot,top) for (lli i=bot; i<top; i++)
#define f2(i,top,bot) for (lli i=top-1; i>=bot; i--)
#define el else
#define elif else if
#define INF 2147483647
#define nl cout << endl
#define td cout << 
#define vi vector<lli>
#define mii map<lli,lli>
#define mib map<lli,bool>
#define pii pair<lli,lli>
#define pqi priority_queue<lli>

typedef struct node
{
    int start;
    int end;
    node* next;
}node;

typedef struct s_list
{
    unsigned size;
    node* head;
    node* tail;
}s_list;

void CreateNewList(s_list* myList)
{
    myList->head = NULL;
    myList->tail = NULL;
    myList->size = 0;
}

node* CreateNewNode(int start, int end)
{
    node* newNode = (node*)malloc(sizeof(node*));
    newNode->start = start;
    newNode->end = end;
    // cout<<"newNode succ"<<endl;
    return newNode;
}

bool IsEmpty(s_list* myList)
{
    if(myList->head == NULL) return true;
    return false;
    // return (&myList->head == NULL);
}

void PushBack(s_list* myList, node* newNode)
{
    if(IsEmpty(myList))
    {
        myList->head = newNode;
    }
    else
    {
        myList->tail->next = newNode;
    }

    myList->tail = newNode;
    myList->size++;
    // cout<<"insert succ"<<endl;
}

void PopBack(s_list* myList)
{
    node* temp = myList->tail;
    free(temp);
    myList->size--;
    // cout<<"popped succ"<<endl;
}

void PushMid(s_list* myList, node* newNode)
{
    node* temp = (myList)->head;
    if(newNode->start < temp->start)
    {
        newNode->next = temp;
        (myList)->head = newNode;
        (myList)->size++;
    }
    else
    {
        node* prev = temp;
        while(temp != NULL)
        {
            if(temp->start > newNode->start)
            {
                newNode->next = temp;
                prev->next = newNode;
                (myList)->size++;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL) PushBack(myList, newNode);
    }
}

void PrintList(s_list* myList)
{
    node* temp = myList->head;
    while(temp != NULL)
    {
        cout<<temp->start<<" "<<temp->end<<endl;
        temp = temp->next;
    }
}

int main()
{
    s_list myList;
    CreateNewList(&myList);
    int n;
    scanf("%d",&n);
    // while(1)
    for(int i=0; i<n; i++)
    {
        int cs, ce;
        cin >> cs >> ce;
        // if(cs == 0 && ce == 0) break;
        node* newNode = CreateNewNode(cs,ce);
        PushBack(&myList, newNode);
    }

    node* cur = (&myList)->head;
    node* next = cur->next;
    while(next != NULL)
    {
        if(next->start <= cur->end)
        {
            // cur->start = cur->start;
            cur->end = max(cur->end, next->end);
            node* temp = next;
            if(next->next != NULL)
            {
                cur->next = next->next;
                next = next->next;
                free(temp);
            }
            else
            {
                cur->next = NULL;
                free(next);
                break;
            }
        }
        else
        {
            cur = next;
            next = next->next;
        }
        
    }
    // cout<<"Result"<<endl;
    PrintList(&myList);
}

/*
6
1 2
3 5
4 8
6 7
8 10
12 16

3
1 3
2 5
6 9

8
1 3
2 4
3 5
4 6
5 7
6 8
7 9
8 10


*/