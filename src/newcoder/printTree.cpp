#include <queue>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//二叉树，按行打印
void printTree(TreeNode* root) {
        // write code here
        TreeNode *last=root; //表示当前打印行的最后一个节点。
        TreeNode *cur;      //当前正在打印的节点
        TreeNode *nlast;    //下一行的最后一个节点
        queue<TreeNode *> q;//FIFO保存要打印的节点
        q.push(root);
        cur = root;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            cout<<cur->val<<" ";
            //将当前打印节点的左右孩子加入到队列中，nlast跟踪加入队列的节点。
            //nlast始终表示最后一个加入队列的节点。
            if (cur->left != NULL){
                nlast = cur->left;
                q.push(nlast);
            }
            if (cur->right != NULL){
                nlast = cur->right;
                q.push(nlast);
            }
            if (cur == last){ //如果当前打印的节点是当前行的最后一个节点，就打印换行符，并且更新当前行的最后一个节点
                cout<<endl;
                last = nlast;
            }
            
        }
        
    }