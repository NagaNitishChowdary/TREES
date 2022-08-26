#include<bits/stdc++.h>
using namespace std;

struct tree{
    int data;
    struct tree *left;
    struct tree *right;
    tree(int val){
        data=val;
        left=right=NULL;
    }
};

#define node struct tree 

void preorder(node *p){
    if(p==NULL) return ;
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}

void inorder(node *p){
    if(p==NULL) return;
    inorder(p->left);
    cout<< p->data <<" ";
    inorder(p->right);
}

void postorder(node *p){
    if(p==NULL) return;
    postorder(p->left);
    postorder(p->right);
    cout<< p->data <<" ";
}

void levelorder(node *p){
    vector<vector<int>>ans;
    if(p==NULL) return;
    queue<node*>q;
    q.push(p);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node *knnc=q.front();
            q.pop();
            if(knnc->left!=NULL) q.push(knnc->left);
            if(knnc->right!=NULL) q.push(knnc->right);
            level.push_back(knnc->data);
        }
        ans.push_back(level);
    }
    //return ans;
    for(auto vctr:ans){
        for(auto it:vctr){
            cout<<it<< " ";
        }
        //cout<<"\n";
    }
}

int main(){
    struct tree *root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->right=new tree(4);
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    /*
    vector<vector<int>>k=levelorder(root);
    for(auto vctr:k){
        for(auto it:vctr){
            cout<<it<< " ";
        }
        //cout<<"\n";
    }
    */
    levelorder(root);
    cout<<"\n";
}
