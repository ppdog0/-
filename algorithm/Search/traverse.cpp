#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct treenode
{
    int value;
    treenode *left = nullptr;
    treenode *right = nullptr;
};
treenode *root, *l1, *l2, *l3, *l4, *l5, *l6;
void data()
{
    root = new treenode;
    l1 = new treenode;
    l2 = new treenode;
    l3 = new treenode;
    l4 = new treenode;
    l5 = new treenode;
    l6 = new treenode;
    root->value = 5;
    l1->value = 3;
    l2->value = 4;
    l3->value = 1;
    l4->value = 2;
    l5->value = 6;
    l6->value = 7;
    root->left = l1;
    l1->left = l5;
    l1->right = l6;
    root->right = l2;
    l2->left = l3;
    l2->right = l4;
}

void preTraverse() {
    stack<treenode*> s;
    s.push(root);
    while (!s.empty()) {
        treenode* t = s.top();
        s.pop();
        cout << t->value << " ";
        if (t->right)
            s.push(t->right);
        while (t->left)
        {
            t = t->left;
            cout << t->value << " ";
            if (t->right)
                s.push(t->right);
        }
    }
}

void inTraverse() {
    stack<treenode*> s;
    treenode* t = root;
    while( t || !s.empty()) {
        while (t) {
            s.push(t);
            t = t->left;
        }
        if (s.empty())
            break;
        t = s.top();
        s.pop();
        cout << t->value << " ";
        t = t->right;
    }
}

void postTraverse() {
    stack<treenode *> s;
    s.push(root);
    treenode *t = root->left;
    treenode *preNode = nullptr;
    while(!s.empty()) {
        while(t && t!=preNode) {
            s.push(t);
            t = t->left;
        }
        if(s.empty())
            break;
        t = s.top();
        if (t->right && t->right!=preNode)
            t = t->right;
        else {
            cout << t->value << " ";
            preNode = t;
            s.pop();
        }
    }
}

void layerTraverse() {
    queue<treenode*> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            treenode* t = q.front();
            q.pop();
            cout << t->value << " ";
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        cout << endl;
    }
}

int main()
{
    data();
    layerTraverse();
    cout << endl;
    preTraverse();
    cout << endl;
    inTraverse();
    cout << endl;
    postTraverse();
}