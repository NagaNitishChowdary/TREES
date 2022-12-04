// PROBLEM LINK --- https://leetcode.com/problems/maximum-width-of-binary-tree/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

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

// USES LEVEL ORDER TRAVERSAL

int widthOfBinaryTree(node* root) {
    if(root == NULL) return 0 ;
    long long int ans = 0 ;
    queue<pair<node*,int>> q ;
    q.push({root,0}) ;
    while(!q.empty()){
        long long int size = q.size() ;
        long long int mmin = q.front().second ;
        long long int first,last ;
        for(int i=0 ; i<size ; i++){
            long long int curr_id = q.front().second - mmin ;
            node *knnc = q.front().first ;
            q.pop() ;
            if(i == 0) first = curr_id ;
            if(i == size-1) last = curr_id ;
            if(knnc->left) q.push({knnc->left,curr_id*2+1}) ;
            if(knnc->right) q.push({knnc->right,curr_id*2+2}) ;
            
        }
        ans = max(ans,last-first+1) ;
    }
    return ans ;
}

int main()
{
    node *root = new node(1) ;
    root -> left = new node(3) ;
    root -> right = new node(2) ;
    root -> left -> left = new node(5) ;
    root -> left -> right = new node(3) ;
    root -> right -> right = new node(9) ;
    cout << widthOfBinaryTree(root) << endl ;

    return 0 ; 
}
