
#include<stack>
#include <iostream>
//二叉树的遍历
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//前序遍历，递归方法
//中，左，右
void preOrderRecur(TreeNode *head ){
    if (head == NULL)
        return;
    cout<<head->val<<" ";
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}
//非递归方法
void preOrder(TreeNode *head){
    stack<TreeNode*> stk; //创建一个堆栈
    stk.push(head); //先将头结点压入栈
    while(!stk.empty()){ //直到栈为空，就退出循环
        //将当前的栈顶弹出记为cur，并打印cur的值
        TreeNode *cur = stk.top(); 
        stk.pop();
        cout<<cur->val<<" ";
        //如果cur的右孩子不为NULL则将其压入栈
        if (cur->right != NULL)
            stk.push(cur->right);
        //如果cur的左孩子不为NULL则将其压入栈
        if (cur->left != NULL)
            stk.push(cur->left);
        
    }
}
//中序遍历打印：左，中，右
void inOrderRecur(TreeNode *head ){
    if (head == NULL)
        return;
    inOrderRecur(head->left);
    cout<<head->val<<" ";
    inOrderRecur(head->right);
}
//中序遍历非递归
void inOrder(TreeNode *head){
    stack<TreeNode*> stk; 
    TreeNode *cur = head;//cur等于头结点
    while(!stk.empty() || cur != NULL){ //栈为空且cur为NULL，退出循环，遍历结束
        if ( cur!= NULL ){ //一直遍历cur的左孩子，不为空就入栈 
            stk.push(cur);
            cur = cur->left;
        }
        else{ //如果cur的左孩子为空，就将当前栈顶弹出并打印，取栈顶的右孩子
            TreeNode *node;
            node = stk.top();
            stk.pop(); 
            cout<<head->val<<" ";
            cur = node->right;        
        }

    }      
}
//后序遍历 ：左，右，中
void posOrderRecur(TreeNode *head){
    if (head == NULL)
        return;
    posOrderRecur(head->left);
    posOrderRecur(head->right);
    cout<<head->val<<" ";
}
//后序遍历非递归：
//需要准备两个栈
void posOrder(TreeNode *head ){
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(head); //先将头结点入栈
    while(!s1.empty()){  //直到栈为空
        TreeNode *cur;
        cur = s1.top(); //将栈顶弹出，压入第二个栈中
        s1.pop();
        s2.push(cur);
        if (cur->left != NULL) //左孩子不为NULL，入栈
            s1.push(cur->left);
        if (cur->right != NULL) //右孩子不为NULL，入栈
            s1.push(cur->right);
    }
    while(!s2.empty()){ //依次弹出第二个栈的栈顶，就是后序遍历的顺序
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
}
