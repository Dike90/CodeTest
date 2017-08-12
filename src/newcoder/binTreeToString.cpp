   #include<string>
   #include <stack>
   using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//二叉树序列化，前序遍历,非递归方法
//如果遇到空节点就用"#!"代替。‘!’表示当前节点结束，'#'表示是空节点
//节点值为12 则转化为"12!"
string toString(TreeNode* root) {
    // write code here
    string str;
    if (root == NULL)
        return "#!";    
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *cur = s.top();
        if (cur == NULL){
            str += "#!";
            continue;
        }
        str += to_string(cur->val);
        s.pop();
        
        if (cur->right != NULL){
            s.push(cur->right);
        }
        else
            s.push(NULL);
        if (cur->left != NULL)
            s.push(cur->left);
        else
            s.push(NULL);
    }
    return str;
}


//前序遍历序列化，递归方法
void preOrderRecur(TreeNode *head, string &str){
    if (head == NULL){
        str +="#!";
        return;
    }
    str += to_string(head->val)+'!';
    preOrderRecur(head->left,str);
    preOrderRecur(head->right, str);
    
}

string TreeToString(TreeNode *root){
    if (root == NULL)
        return "#!";
    string str;
    preOrderRecur(root,str);
    return str;
}
