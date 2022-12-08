// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/burning-tree/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563

// THE INTUTION BEHIND THIS IS THE PREVIOUS PROBLEM --- ie THE NODES AT DISTANCE K 
// FROM THE GIVEN START NODE WE TRAVERSE UNTIL THE LAST NODE ie UNTIL QUEUE BECOMES EMPTY ie INCREMENT COUNT 

#include<bits/stdc++.h>
using namespace std ;

struct Node{
    int data ;
    Node *left , *right ;
    Node(int val){
        left = right = NULL ;
        data = val ;
    }
};

Node* make_parents(Node *root,unordered_map<Node*,Node*> &parents,int start){
    queue<Node*> q ;
    q.push(root) ;
    Node *res ;
    while(!q.empty()){
        int size = q.size() ;
        for(int i=0 ; i<size ; i++){
            Node *naga = q.front() ;
            q.pop() ;
            if(naga->data == start) res = naga ;
            if(naga -> left){
                q.push(naga->left) ;
                parents[naga->left] = naga ; 
            }
            if(naga -> right){
                q.push(naga->right) ;
                parents[naga->right] = naga ;
            }
        }
    }
    return res ;   
}
  
int mintime(Node *root,unordered_map<Node*,Node*> &parents){
    int cnt = 0 ;
    unordered_map<Node*,bool> vis ;
    queue<Node*> queue ;
    vis[root] = true ;
    queue.push(root) ;
    while(!queue.empty()){
        int size = queue.size() ;
        cnt++ ;
        for(int i=0 ; i<size ; i++){
            Node *niti = queue.front() ;
            queue.pop() ;
            if(niti -> left && !vis[niti -> left]){
                queue.push(niti -> left) ;
                vis[niti -> left] = true ;
                
            }
            if(niti -> right && !vis[niti -> right]){
                queue.push(niti -> right) ;
                vis[niti -> right] = true ;
            }
            if(parents[niti] && !vis[parents[niti]]){
                queue.push(parents[niti]) ;
                vis[parents[niti]] = true ;
            }
        }
    }
    return cnt-1 ;
}
  
int minTime(Node* root, int target) 
{
    // Your code goes here
    unordered_map<Node*,Node*> parents ;
    Node *knnc = make_parents(root , parents ,target) ;
    return mintime(knnc,parents) ;
}

int main()
{
    Node *root = new Node(1) ;
    root -> left = new Node(2) ;
    root -> right = new Node(3) ;
    root -> left -> left = new Node(4) ;
    root -> left -> left -> left = new Node(5) ;
    root -> left -> left -> left -> left = new Node(6) ;

    int start = 6 ;
    cout << minTime(root,start) ;
    return 0 ;
}
