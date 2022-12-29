// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/floor-in-bst/1?category%5B%5D=Binary%20Search%20Tree&page=1&sortBy=accuracy&query=category%5B%5DBinary%20Search%20Treepage1sortByaccuracy

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

int floorInBST(node * root, int X)
{
    // Write your code here.
    int floor = -1 ;
    while(root){
        if(root -> data == X) return X ;
        if(root -> data > X) root = root -> left ;
        else{ floor = root -> data ; root = root -> right ;}
    }
    return floor ;
}

int main()
{
    node *root = new node(10) ;
    root -> left = new node(8) ;
    root -> right = new node(11) ;
    cout << floorInBST(root,9) << endl ;
    return 0 ; 
}
