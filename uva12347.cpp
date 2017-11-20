/* Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3769 */
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v, left = right = NULL; }
};

void insert(Node* &root, int v)
{
    if(root == NULL)
    {
        root = new Node(v);
        return;
    }
    
    if(v > root->data) insert(root->right, v);
    else 			   insert(root->left, v);
}

void PostOrder(Node* root)
{
    if(root == NULL)	return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << "\n";
}

int main()
{
    int v;
    Node* root = NULL;
    while(cin >> v)
        insert(root, v);
    PostOrder(root);
}