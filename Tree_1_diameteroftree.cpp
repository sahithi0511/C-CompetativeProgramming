#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node *left;
   Node *right;

};
Node *newnode(int d)
{
    Node *root=(Node*)malloc(sizeof(Node));
    root->data=d;
    root->left=root->right=NULL;
    return root;
}
Node *insert(Node *root,int val)
{
    if(root==NULL)
    {
        root=newnode(val);
    }
    else if(val<=root->data)
    {
        root->left=insert(root->left,val);
    }
    else
    {
        root->right=insert(root->right,val);
    }
    return root;
}
int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left),height(root->right))+1;
    }
    
}
int DM(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int ld=DM(root->left);
    int rd=DM(root->right);
    return max(lh+rh+1,max(ld,rd));
}
int main()
{
    Node *root=NULL;
    int n;
    cin>>n;
    int val;
    while(n--)
    {
        
        cin>>val;
        root=insert(root,val);

    }
    cout<<DM(root);
}