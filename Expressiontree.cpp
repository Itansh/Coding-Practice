#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string info;
    node *left = NULL, *right = NULL;
    node(string x)
    {
        info = x;
    }
};
int toInt(string s)
{
    int num = 0;
    for (int i=0; i<s.length();  i++)
        num = num*10 + (int(s[i])-48);
    return num;
}
int eval(node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return toInt(root->info);
    int l_val = eval(root->left);
    int r_val = eval(root->right);
    if (root->info=="+")
        return l_val+r_val;
 
    if (root->info=="-")
        return l_val-r_val;
 
    if (root->info=="*")
        return l_val*r_val;
 
    return l_val/r_val;
}
int main()
{
    node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("20");
    cout << eval(root) << endl;
 
    delete(root);
 
    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");
 
    cout << eval(root);
    return 0;
}
