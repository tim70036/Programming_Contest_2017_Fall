/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/205 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> queryAns;
class Node
{
public:
    int value;
    Node* left;
    Node* right;
    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

inline int abs(int x) { return (x>0)? x : -x; }

void insert(Node** root, int v)
{
    if(*root == NULL)
    {
        *root = new Node(v);
        return;
    }
    
    if(v > (*root)->value)	insert(&((*root)->right), v);
    else					insert(&((*root)->left), v);
}

int query(Node* root, int v)
{
    int ret = root->value;
    
    /* Right */
    if(v > root->value && root->right)
    {
        /* Closest value from subtree */
        int subValue = query(root->right, v);
        
        /* Better than current node ? */
        int diffCur = abs(v - root->value);
        int diffSub = abs(v - subValue);
        
        /* Same */
        if(diffCur == diffSub)
        {
            queryAns.push_back(root->value);
        }
        /* Better */
        else if(diffCur < diffSub)
        {
            queryAns.clear();
            queryAns.push_back(root->value);
        }
        else
        {
            ret = subValue;
        }
    }
    /* Left */
    else if(v < root->value && root->left)
    {
        /* Closest value from subtree */
        int subValue = query(root->left, v);
        
        /* Better than current node ? */
        int diffCur = abs(v - root->value);
        int diffSub = abs(v - subValue);
        
        /* Same */
        if(diffCur == diffSub)
        {
            queryAns.push_back(root->value);
        }
        /* Better */
        else if(diffCur < diffSub)
        {
            queryAns.clear();
            queryAns.push_back(root->value);
        }
        else
        {
            ret = subValue;
        }
    }
    else
    {
        ret = root->value;
        queryAns.push_back(ret);
    }
    /* Return for comparing */
    return ret;
}

inline int findMax(Node* root)
{
    while(root->right)
        root = root->right;
    return root->value;
}

void del(Node** root, int v)
{
    if(*root == NULL)	return;
    
    /* Searching */
    if(v > (*root)->value )		del(&((*root)->right), v);
    else if(v < (*root)->value) del(&((*root)->left), v);
    /* Start delete */
    else
    {
        if((*root)->left == NULL || (*root)->right == NULL)
        {
            Node* tmp = *root;
            *root = ((*root)->left == NULL) ? (*root)->right : (*root)->left;
            delete tmp;
        }
        else
        {
            (*root)->value = findMax((*root)->left);
            del(&((*root)->left), (*root)->value);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Node* root = NULL;
    int n; cin >> n;
    while(n--)
    {
        string act;
        int v;
        cin >> act >> v;
        if(act == "insert")
            insert(&root, v);
        else if(act == "delete")
            del(&root, v);
        else if(act == "query")
        {
            queryAns.clear();
            query(root, v);
            sort(queryAns.begin(), queryAns.end());
            for(int i=0 ; i<queryAns.size() ; i++)
            {
                if(i > 0) cout << " ";
                cout << queryAns[i];
            }
            cout << "\n";
        }
    }
}