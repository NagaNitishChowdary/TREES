// PROBLEM LINK --- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

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

void makeParents(node* root,unordered_map<node*,node*> &parent_track){
    queue<node*> q ;
    q.push(root) ;
    while(!q.empty()){
        int size = q.size() ;
        for(int i=0 ; i<size ; i++){
            node *node = q.front() ;
            q.pop() ;
            if(node->left != NULL){
                parent_track[node->left] = node ;
                q.push(node->left) ;
            }
            if(node->right != NULL){
                parent_track[node->right] = node ;
                q.push(node->right) ;
            }
        }
    }
}

vector<int> distanceK(node* root, node* target, int k) {
    unordered_map<node*,node*> parent_track ;
    // USING LEVEL ORDER TRAVERSAL STORE ALL THE PARENTS FOR ITS CHILDREN
    makeParents(root,parent_track) ;

    unordered_map<node*,bool> visited ;
    queue<node*> queue ;
    queue.push(target) ;
    visited[target] = true ;
    int curr_level = 0 ;
    while(!queue.empty()){
        int size = queue.size() ;
        if(curr_level == k) break ;
        curr_level++ ;
        for(int i=0 ; i<size ; i++){
            node *node = queue.front() ;
            queue.pop() ;
            if(node -> left && !visited[node->left]){
                queue.push(node->left) ;
                visited[node->left] = true ;
            }
            if(node -> right && !visited[node->right]){
                queue.push(node->right) ;
                visited[node->right] = true ;
            }
            if(parent_track[node] && !visited[parent_track[node]]){
                queue.push(parent_track[node]) ;
                visited[parent_track[node]] = true ;
            }
        }
    }
    vector<int> ans ;
    while(!queue.empty()){
        ans.emplace_back(queue.front() -> data) ;
        queue.pop() ;
    }
    return ans ;
}

int main()
{
    node *root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    root -> left -> left = new node(4) ;
    root -> left -> right = new node(5) ;
    root -> right -> left = new node(6) ;
    root -> right -> right = new node(7) ;

    vector<int> ans1 ;
    ans1= distanceK(root,root,2) ;

    for(auto it:ans1){
        cout << it << " " ;
    }

    return 0 ; 
}
