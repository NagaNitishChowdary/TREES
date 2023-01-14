// PROBLEM LINK --- https://leetcode.com/problems/binary-search-tree-iterator/
// PROBLEM LINK --- https://www.interviewbit.com/problems/bst-iterator/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/bst-iterator_1112601

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack< TreeNode* > st ;
public:
    
    void pushAll(TreeNode *node){
        while(node != NULL){
            st.push(node) ;
            node = node -> left ;
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushAll(root) ;
    }
    
    int next() {
        TreeNode *topele = st.top() ;
        st.pop() ;
        pushAll(topele -> right) ;
        return topele -> val ;
    }
    
    bool hasNext() {
        if(!st.empty()) return true ;
        else return false ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
