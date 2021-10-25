
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    //cout << endl;
}
void in_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void bfs(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
        cout << f->data << " ";
        q.pop();
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}
int maxdept(node*root){
    if (root == NULL)
    {
        return 0;
    }
    int maxleft= maxdept(root->left);
    int maxright= maxdept(root->right);
    return max(maxleft,maxright)+1;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    //root->left->left->left = new node(-2);
    preorder(root);
    cout << endl;
    in_order(root);
    cout << endl;
    postorder(root);
    cout << endl;
    bfs(root);
     cout << endl;
     cout<<maxdept(root);
    return 0;
}
