// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

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

int findCeil(node *nod, int x){
    // Write your code here.
    int ceil = -1 ;
    while(nod){
        if(x == nod -> data){
            ceil = x ; return ceil ;
        }
        if(x > nod -> data) nod = nod -> right ;
        else{ ceil = nod -> data ; nod = nod -> left ; }
    }
    return ceil ;
    
}

int main()
{
    node *root = new node(10) ;
    root -> left = new node(8) ;
    root -> right = new node(11) ;
    cout << findCeil(root,9) << endl ;
    return 0 ; 
}
