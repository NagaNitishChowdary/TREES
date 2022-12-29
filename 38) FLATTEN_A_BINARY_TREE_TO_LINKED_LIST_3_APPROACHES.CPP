// PROBLEM LINK --- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/flatten-binary-tree-to-linked-list_1112615?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

// APPROACH 2 

#include<bits/stdc++.h>
using namespace std ;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL) return root;
    stack< TreeNode<int>* > st ;
    st.push(root) ;
    while(!st.empty()){
        TreeNode<int> *node = st.top() ; 
        st.pop() ;
        if(node -> right) st.push(node -> right) ;
        if(node -> left) st.push(node -> left) ;
        if(!st.empty()) node -> right = st.top() ;
        node -> left = NULL ;
    }
    return root ;
}

void preorder(TreeNode<int> *h){
    if(h == NULL) return ;
    cout << h -> data << " " ;
    preorder(h -> left) ;
    preorder(h -> right) ;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1) ;
    root -> left = new TreeNode<int>(2) ;
    root -> right = new TreeNode<int>(3) ;
    preorder(root) ; cout << endl ;
    TreeNode<int> *knnc = flattenBinaryTree(root) ;
    preorder(knnc) ; cout << endl ;
    return 0 ; 
}
