#include <iostream>
using namespace std;
class node
{
public:
    int num;
    node* next;
    node* prev;
};

/* Dummy head */
node  head[2000000];
/* Handler for each node */
node* handler[2000000];

void InsertBack(node* from, node* to)
{
    /* Delete fromNode */
    node* prevNode = from->prev;
    node* nextNode = from->next;
    
    prevNode->next = nextNode;
    if(nextNode != NULL)	nextNode->prev = prevNode;
    
    /* Insert */
    nextNode = to->next;
    
    to->next = from;
    from->prev = to;
    from->next = nextNode;
    if(nextNode != NULL)	nextNode->prev = from;
}

void AppendBack(int from, int to)
{
    node* a = head[from].next;
    node* b = head[to].next;
    
    /* Delete from*/
    head[from].next = NULL;
    
    /* to or from has no node */
    if(a == NULL)	return;
    if(b == NULL)
    {
        head[to].next = a;
        a->prev = &head[to];
        return;
    }
    
    /* Move */
    while(b->next != NULL)	b = b->next;
    b->next = a;
    a->prev = b;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    /* Init node */
    for(int i=1 ; i<=n ; i++)
    {
        /* New node */
        handler[i] = new node();
        handler[i]->num = i;
        handler[i]->next = NULL;
        handler[i]->prev = &head[i];
        
        /* into roll */
        head[i].num = -1;
        head[i].next = handler[i];
        head[i].prev = NULL;
    }
    
    /* Read command */
    int act, a, b;
    while(m--)
    {
        cin >> act >> a >> b;
        if(act == 0)	InsertBack(handler[a], handler[b]);
        else	AppendBack(a, b);
    }
    
    /* Output */
    for(int i=1 ; i<=n ; i++)
    {
        cout << "#" << i << ":";
        node* cur = head[i].next;
        for( ; cur != NULL ; cur = cur->next)
            cout << " " << cur->num;
        cout << "\n";
    }
}