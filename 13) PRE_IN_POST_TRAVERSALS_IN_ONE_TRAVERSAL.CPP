#include<bits/stdc++.h>
using namespace std ;

struct TreeNode{
    int data ;
    TreeNode *left,*right ;
    TreeNode(int val){
        data = val ;
        left = right = NULL ;
    }
};

vector<vector<int>> preInPostTraversal(TreeNode *root){
    stack< pair<TreeNode*,int> > st ;
    st.push({root,1}) ;
    vector<int> preorder , inorder , postorder ;
    vector<vector<int>> ans ;
    if(root == NULL) return {} ;
    while(!st.empty()){
        auto it=st.top() ;
        st.pop() ;

        // THIS IS THE FIRST PART OF THE PREORDER
        // INCREMENT 1 TO 2
        // PUSH THE LEFT SIDE OF THE TREE
        if(it.second == 1){
            preorder.emplace_back(it.first -> data) ;
            it.second++ ;
            st.push(it) ;

            if(it.first->left != NULL) st.push({it.first->left,1}) ;
        }

        // THIS IS THE SECOND PART OF INORDER
        // INCREMENT 2 TO 3
        // PUSH RIGHT
        else if(it.second == 2){
            inorder.emplace_back(it.first -> data) ;
            it.second++ ;
            st.push(it) ;

            if(it.first -> right != NULL) st.push({it.first->right,1});
        }

        // DONT PUSH IT BACK AGAIN
        else postorder.emplace_back(it.first->data) ;
    }
    ans.emplace_back(preorder) ;
    ans.emplace_back(inorder) ;
    ans.emplace_back(postorder) ;
    return ans ;
}


int main()
{
    TreeNode *root = new TreeNode(1) ;
    root -> left = new TreeNode(2) ;
    root -> right = new TreeNode(3) ;
    vector<vector<int>> knnc = preInPostTraversal(root) ;
    for(auto vctr:knnc){
        for(auto it:vctr) cout << it << " " ;
        cout << endl ;    
    }
    cout << endl ;
    return 0 ; 
}
