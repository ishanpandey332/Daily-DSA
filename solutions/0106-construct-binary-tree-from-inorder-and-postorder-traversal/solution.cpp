class Solution {
public:
    unordered_map<int, int> mp; 
    int postIndex;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

     
        int inIndex = mp[rootVal];

        
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd);
        root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, 0, n - 1);
    }
};

