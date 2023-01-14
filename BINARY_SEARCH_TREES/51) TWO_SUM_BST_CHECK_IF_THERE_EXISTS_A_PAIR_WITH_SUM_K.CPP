// PROBLEM LINK --- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class BSTIterator{
    stack < Node* > st ;
    // reverse -> true -> before 
    // reverse -> false -> next 
    bool reverse = true ;
public:
    BSTIterator(Node* root,bool isReverse){
        reverse = isReverse ;
        pushAll(root) ;
    }
    
    /** @ RETURN WHEATHER WE HAVE A NEXT SMALLEST NUMBER */
    bool hasNext(){
        return !st.empty() ;
    }
    
    /** @ RETURN THE NEXT SMALLEST NUMBER */
    int next(){
        Node *tmpNode = st.top() ;
        st.pop() ;
        if(!reverse) pushAll(tmpNode -> right) ;
        else pushAll(tmpNode -> left) ;
        return tmpNode -> data ;
    }
    
private:
    void pushAll(Node *node){
        for( ; node!=NULL ; ){
            st.push(node) ;
            if(reverse == true) node = node -> right ;
            else node = node -> left ;
        }
    }
};
    
void inorder(struct Node *node,map<int,int> &mpp){
    if(node == NULL) return ;
    inorder(node -> left , mpp) ;
    mpp[node -> data]++ ;
    inorder(node -> right , mpp) ;
}

int isPairPresent1(struct Node *root, int target)
{
//add code here.
map<int,int> mpp ;
inorder(root , mpp) ;
for(auto it:mpp){
    auto knnc = mpp.find(target-it.first) ;
    if(knnc != mpp.end()){
        if(it.first == target-it.first){
            if(it.second > 1) return true ;
        } else return true ;
    }
}
return false ;
}

int isPairPresent(struct Node *root, int target){
    if(!root) return false ;
    // l for next 
    BSTIterator l(root , false) ;
    // r for before
    BSTIterator r(root , true) ;
    
    int i = l.next() ;
    int j = r.next() ; // r.before() 
    while(i<j){
        if(i+j == target) return true ;
        else if(i+j < target) i = l.next() ;
        else j = r.next() ;
    }
    return false ;
}
    
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);    
       cout << isPairPresent(root, k) << endl;
   }
   return 0;
}
