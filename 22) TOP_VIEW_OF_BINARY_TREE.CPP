

#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    node *left,*right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
};

vector<int> topView(node *root){
    vector<int> ans ;
    if(root == NULL) return ans ;
    map<int,int> mpp ;
    queue<pair<node*,int>> q ;
    q.push({root,0}) ;
    while(!q.empty()){
        auto it = q.front() ;
        q.pop() ;
        node *n = it.first ;
        int line = it.second ;
        if(mpp.find(line) == mpp.end()) mpp[line] = n->data ;
        if(n->left != NULL) q.push({n->left,line-1}) ;
        if(n->right != NULL) q.push({n->right,line+1}) ;
    }
    for(auto it:mpp) ans.emplace_back(it.second) ;
    return ans ;
}

int main()
{
    node* root = new node(1) ;
    root->left = new node(2) ;
    root->right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> left -> right = new node(5) ;
    root -> left -> right -> left = new node(6) ;
    root -> right -> right = new node(7) ;
    vector<int> knnc = topView(root) ;
    for(auto it:knnc) cout << it << " " ;
    cout << endl ;
    return 0;
}
