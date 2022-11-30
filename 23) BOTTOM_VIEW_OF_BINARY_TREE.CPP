#include <bits/stdc++.h>
using namespace std;

// topView = 4 2 1 3 7 
// bottomView = 4 8 6 9 7 

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
    map<int,int>mpp ;
    queue<pair<node*,int>> q ;
    q.push({root,0}) ;
    while(!q.empty()){
        auto it = q.front() ;
        q.pop() ;
        node *knnc = it.first ;
        int line = it.second ;
        if(mpp.find(line) == mpp.end()) mpp[line] = knnc -> data ;
        if(knnc -> left != NULL) q.push({knnc->left,line-1}) ;
        if(knnc -> right != NULL) q.push({knnc->right,line+1}) ;
    }
    for(auto it:mpp){
        ans.emplace_back(it.second) ;
    }
    return ans ;
}

vector<int> bottomView(node *root){
    vector<int> ans ;
    if(root == NULL) return ans ;
    map<int,int>mpp ;
    queue<pair<node*,int>> q ;
    q.push({root,0}) ;
    while(!q.empty()){
        auto it = q.front() ;
        q.pop() ;
        node *knnc = it.first ;
        int line = it.second ;
        // if(mpp.find(line) == mpp.end()) mpp[line] = knnc -> data ;
        mpp[line] = knnc -> data ;
        if(knnc -> left != NULL) q.push({knnc->left,line-1}) ;
        if(knnc -> right != NULL) q.push({knnc->right,line+1}) ;
    }
    for(auto it:mpp){
        ans.emplace_back(it.second) ;
    }
    return ans ;
}

int main(){
    node *root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> left -> right = new node(5) ;
    root -> left -> right -> left = new node(8) ;
    root -> left -> right -> right = new node(9) ;
    root -> right -> left = new node(6) ;
    root -> right -> right = new node(7) ;
    
    cout << "TOP VIEW" << endl ;
    vector<int> top = topView(root) ;
    for(auto it:top) cout << it << " " ;
    cout << endl ;

    cout<< "BOTTOM VIEW" << endl ;
    vector<int> bottom = bottomView(root) ;
    for(auto it:bottom) cout << it << " " ;
    cout << endl ;
    
   return 0;
}
