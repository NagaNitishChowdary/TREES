// PROBLEM LINK --- https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/largest-bst/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeValue{
public:
    int maxNode , minNode , maxSize ;
    
    NodeValue(int minNode , int maxNode , int maxSize){
        this -> minNode = minNode ;
        this -> maxNode = maxNode ;
        this -> maxSize = maxSize ;
    }
};

NodeValue largestBSTSubTreeHelper(Node *root){
    // AN EMPTY TREE IS A BST OF SIZE 0 
    if(root == NULL) return NodeValue(INT_MAX , INT_MIN , 0) ;
    // GET VALUES FROM LEFT AND RIGHT SUBTREES OF CURRENT TREE
    // POSTORDER
    auto left = largestBSTSubTreeHelper(root -> left) ;
    auto right = largestBSTSubTreeHelper(root -> right) ;
    
    // CURRENT NODE IS GREATER THAN MAX IN LEFT AND SMALLER THAN MIN IN RIGHT
    // , IT IS A VALID BST 
    if((left.maxNode < root -> data) && (root -> data < right.minNode)){
        // IT IS A BST 
        return NodeValue(min(root -> data , left.minNode) 
        , max(right.maxNode , root -> data) , left.maxSize + right.maxSize + 1) ;
    }
    
    // OTHERWISE RETURN [-inf,inf] SO THAT PARENT CAN'T BE A VALID BST 
    return NodeValue(INT_MIN , INT_MAX , max(left.maxSize , right.maxSize)) ;
}

// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    //Your code here
    return largestBSTSubTreeHelper(root).maxSize ;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        cout << largestBst(root) << endl;
    }
    return 0;
}
