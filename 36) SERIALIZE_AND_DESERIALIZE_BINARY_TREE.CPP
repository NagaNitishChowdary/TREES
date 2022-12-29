// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/serialise-deserialise-a-binary-tree_920328?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
// PROBLEM LINK --- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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


string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(root == NULL) return "" ;
    queue<TreeNode<int>*> q;
    q.push(root) ;
    string s = "" ;
    while(!q.empty()){
        TreeNode<int> *curNode = q.front() ;
        q.pop() ;
        if(curNode == NULL) s.append("#,") ;
        else s.append((to_string(curNode->data)+",")) ;
        if(curNode != NULL){
            q.push(curNode -> left) ;
            q.push(curNode -> right) ;
        }
    }
    return s ;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
       if(serialized.size() == 0) return NULL ;
       stringstream s(serialized) ;
       string str ;
       getline(s,str,',') ;
       TreeNode<int> *root = new TreeNode<int>(stoi(str)) ;
       queue<TreeNode<int>*> q ;
       q.push(root) ;
       while(!q.empty()){
           TreeNode<int> *node = q.front() ;
           q.pop() ;
           
           getline(s,str,',') ;
           if(str == "#") node -> left = NULL ;
           else{
               TreeNode<int> *leftNode = new TreeNode<int>(stoi(str)) ;
               node -> left = leftNode ;
               q.push(leftNode) ;
           }
           
           getline(s,str,',') ;
           if(str == "#") node -> right = NULL ;
           else{
               TreeNode<int> *rightNode = new TreeNode<int>(stoi(str));
               node -> right = rightNode ;
               q.push(rightNode) ;
           }
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
    root -> left = new TreeNode<int>(-1) ;
    root -> right = new TreeNode<int>(3) ;
    preorder(root) ; cout << endl ;
    string serialized = serializeTree(root) ;
    TreeNode<int>* knnc =  deserializeTree(serialized) ;
    preorder(knnc) ; cout << endl ;
    return 0 ; 
}

