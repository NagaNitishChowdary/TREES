// PROBLEM LINK --- https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// MORRIS TRAVERSAL (SPACE COMPLEXITY : O(1))
vector<int> inorderTraversal(node* root) {
    vector<int> inorder ;
    if(root == NULL) return inorder ;
    node *cur = root ;
    while(cur != NULL){
        // CASE 1 --- IF LEFT NODE DOES NOT EXISTS
        if(cur -> left == NULL){
            inorder.push_back(cur -> data) ;
            cur = cur -> right ;
        }
        // CASE 2 --- IF LEFT NODE EXISTS THEN GO TO LEFT NODE IN 
        // THAT GO TO THE RIGHT MOST GUY AND MAKE THREAD TO THE CURRENT GUY 
        else{
            node *prev = cur -> left ;
            while(prev -> right && prev -> right != cur){
                prev = prev -> right ;
            }
            if(prev -> right == NULL){
                prev -> right = cur ; // ESTABLISHING THREAD
                cur = cur -> left ;
            }
            // IF THE WHILE LOOP EXISTS AT prev->right != curr condition
            else{
                prev -> right = NULL ;
                inorder.push_back(cur -> data) ;
                cur = cur -> right ;
            }
        }
    }
    return inorder ;
}

int main()
{
    node *root = new node(1) ;
    root -> left = new node(2) ;
    root -> right = new node(3) ;
    vector<int> knnc = inorderTraversal(root) ;
    for(auto it:knnc) cout << it << " " ;
    cout << endl ;
    return 0 ; 
}
