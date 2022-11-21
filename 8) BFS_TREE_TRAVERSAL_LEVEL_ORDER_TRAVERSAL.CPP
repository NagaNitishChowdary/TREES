// BREADTH FIRST SEARCH (BFS)
// LEVEL ORDER TRAVERSAL 

#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    struct node *left ;
    struct node *right ;
    node(int val){
        data = val ;
        left = right = NULL ;
    }
};

vector<vector<int>> levelOrder(node *root){
    vector<vector<int>> ans ;
    if(root == NULL) return ans ;
    queue< node* > q ;
    q.push(root) ;
    while(!q.empty()){
        vector<int> level ;
        int size = q.size() ;
        for(int i=0 ; i<size ; i++){
            node *n = q.front() ;
            q.pop() ;
            if(n -> left != NULL) q.push(n -> left) ;
            if(n -> right != NULL) q.push(n -> right) ;
            level.emplace_back(n -> data) ;
        }
        ans.emplace_back(level) ;
    }
    return ans ;

}

int main()
{
    struct node *root = new node(3) ;
    root -> left = new node(9) ;
    root -> right = new node(20) ;
    root -> right -> left = new node(15) ;
    root -> right -> right = new node(7) ;
    vector<vector<int>> knnc ;
    knnc = levelOrder(root) ;
    for(auto vctr:knnc){
        for(auto it:vctr){
            cout << it << " " ;
        }
        cout << endl ;
    }
}
